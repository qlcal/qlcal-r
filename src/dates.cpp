
//  QlCal -- R interface to QuantLib Calendars
//
//  Copyright (C) 2002 - 2026  Dirk Eddelbuettel <edd@debian.org>
//
//  This file is part of QlCal
//
//  QlCal is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  QlCal is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with QlCal.  If not, see <http://www.gnu.org/licenses/>.


// Taken from RQuantLib and adapted

// [[Rcpp::interfaces(r, cpp)]]

#include "qlcal_types.h"
#include "qlcal_declarations.h"
#include "qlcal_as_wrap.h"

#include <boost/date_time/posix_time/conversion.hpp>
#include <chrono>


namespace ql = QuantLib;

QlCal::CalendarContainer gblcal;

//' Set a calendar
//'
//' This function sets the default calendar to the given market or country convention.
//' Note that additional calendar objects can be created with the \code{getCalendar}
//' function.
//'
//' @title Set a calendar
//' @param calstr A character variable containing the market for which a calendar
//' is to be set
//' @return Nothing is returned but the global state is changed
//' @seealso \code{getCalendar}
//' @examples
//' setCalendar("UnitedStates/NYSE")
//' setCalendar("Canada/TSX")
// [[Rcpp::export]]
void setCalendar(std::string calstr) {
    gblcal.setCalendar(calstr);
}

//' Advance a date to the next business day plus an optional shift
//'
//' This function takes a given date and advances it to the next business day
//' under the current (global) calendar setting. If an optional offset value is
//' given it is applied as well.
//'
//' @title Advance a date
//' @param rd A Date object describing the date to be advanced to the
//' next business day.
//' @param days An optional integer offset applied to the date
//' @param unit An optional character value denoting a time unit, default value
//' is \dQuote{Day}, and supported values are \dQuote{Days}, \dQuote{Weeks},
//' \dQuote{Months}, \dQuote{Years}, \dQuote{Hours}, \dQuote{Seconds},
//' \dQuote{Minutes}, \dQuote{Milliseconds}, \dQuote{Microseconds}.
//' @param bdc An optional integer defining a business day convention, default
//' is \dQuote{Following}, and supported values are
//' \dQuote{Following}, \dQuote{ModifiedFollowing}, \dQuote{Preceding},
//' \dQuote{ModifiedPreceding}, \dQuote{Unadjusted},
//' \dQuote{HalfMonthModifiedFollowing} and \dQuote{Nearest}.
//' @param eom An optional boolean toggle whether end-of-month is to be respected
//' @return The advanced date is returned
//' @examples
//' advanceDate(Sys.Date(), 2)  # today to the next biz day, plus 2 days
//' @seealso The \code{advanceUnits} functions offers the same functionality from R.
// [[Rcpp::export]]
Rcpp::Date advanceDate(Rcpp::Date rd, int days=0, const std::string& unit = "Days",
                       const std::string& bdc = "Following", bool eom=false) {
    ql::Calendar cal = gblcal.getCalendar();
    ql::Date d = Rcpp::as<ql::Date>(rd);
    ql::BusinessDayConvention bdcval = getBusinessDayConvention(bdc);
    ql::TimeUnit tuval = getTimeUnit(unit);
    ql::Date newdate = cal.advance(d, days, tuval, bdcval, eom);
    return Rcpp::wrap(newdate);
}

// Internal helper: We either instantiate dates if given or use a default
Rcpp::DateVector createDateVector(Rcpp::Nullable<Rcpp::DateVector> dates) {
    if (dates.isNull()) {       // no argument given so create length one vector of current date
        // C++20   const auto time_pt_utc{std::chrono::system_clock::now()};
        //         const auto current_local_time{std::chrono::current_zone()->to_local(time_pt_utc)};
        // before C++20 it is UTC
        //         const auto n = std::chrono::system_clock::now();
        //         const auto d = std::chrono::duration_cast<std::chrono::hours>(n.time_since_epoch()).count();
        //         datesvec = Rcpp::DateVector(Rcpp::NumericVector{d/24.0}); // C++20 will give us chrono::days
        // so we cheat and ask R to not fall for timezone issues
        // TODO: once R 4.6.0 is out and we have C++20 we can conditionally use it here
        Rcpp::Function f = Rcpp::Function("Sys.Date");
        return f();
    } else {
        return Rcpp::DateVector(dates); // instantiate from Nullable wrapper
    }
}
// Internal helper: We either instantiate cal or use default global one
ql::Calendar getCalendarInstance(Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    if (xp.isNotNull()) {
        Rcpp::XPtr<QlCal::CalendarContainer> p = Rcpp::XPtr<QlCal::CalendarContainer>(xp);
        return p->getCalendar();
    } else {
        return gblcal.getCalendar();
    }
}

//' Test a vector of dates for business day
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is a business day in the currently active (global) calendar.
//'
//' @title Test for business days
//' @param dates An optional Date vector with dates to be examined, if missing the
//' current day is used
//' @param xp An optional calendar object, if missing the default instance is used
//' @return A logical vector indicating which dates are business days
//' @examples
//' isBusinessDay(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isBusinessDay(Rcpp::Nullable<Rcpp::DateVector> dates = R_NilValue,
                                  Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    Rcpp::DateVector datesvec = createDateVector(dates);
    ql::Calendar cal = getCalendarInstance(xp);

    int n = datesvec.size();
    Rcpp::LogicalVector bizdays(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(datesvec);
    for (auto i=0; i<n; i++) {
        bizdays[i] = cal.isBusinessDay(dv[i]);
    }
    return bizdays;
}

//' Test a vector of dates for holiday
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is a holiday in the currently active (global) calendar.
//'
//' @title Test for holidays
//' @param dates An optional Date vector with dates to be examined, if missing the
//' current day is used
//' @param xp An optional calendar object, if missing the default instance is used
//' @return A logical vector indicating which dates are holidays
//' @examples
//' isHoliday(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isHoliday(Rcpp::Nullable<Rcpp::DateVector> dates = R_NilValue,
                              Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    Rcpp::DateVector datesvec = createDateVector(dates);
    ql::Calendar cal = getCalendarInstance(xp);

    int n = datesvec.size();
    Rcpp::LogicalVector holdays(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(datesvec);
    for (auto i=0; i<n; i++) {
        holdays[i] = !cal.isBusinessDay(dv[i]);
    }
    return holdays;
}

//' Test a vector of dates for weekends
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is a weekend in the currently active (global) calendar.
//'
//' @title Test for weekends
//' @param dates An optional Date vector with dates to be examined, if missing the
//' current day is used
//' @param xp An optional calendar object, if missing the default instance is used
//' @return A logical vector indicating which dates are weekends
//' @examples
//' isWeekend(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isWeekend(Rcpp::Nullable<Rcpp::DateVector> dates = R_NilValue,
                              Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    Rcpp::DateVector datesvec = createDateVector(dates);
    ql::Calendar cal = getCalendarInstance(xp);

    int n = datesvec.size();
    Rcpp::LogicalVector weekends(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(datesvec);
    for (auto i=0; i<n; i++) {
        weekends[i] = cal.isWeekend(dv[i].weekday());
    }
    return weekends;
}

//' Test a vector of dates for end-of-month
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is at the end of a month in the currently active (global) calendar.
//'
//' @title Test for end-of-month
//' @param dates A Date vector with dates to be examined
//' @return A logical vector indicating which dates are end-of-month
//' @examples
//' isEndOfMonth(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isEndOfMonth(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::LogicalVector eom(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        eom[i] = cal.isEndOfMonth(dv[i]);
    }
    return eom;
}


//' Compute a vector of dates with end-of-month
//'
//' This function takes a vector of dates and returns another vector of dates
//' of the same length returning at each position whether the corresponding
//' end-of-month date in the currently active (global) calendar.
//'
//' @title Compute end-of-month
//' @param dates A Date vector with dates
//' @return A Date vector with dates which are end-of-month
//' @examples
//' getEndOfMonth(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::DateVector getEndOfMonth(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::DateVector ndates(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        ndates[i] = Rcpp::qlDate2Rcpp(cal.endOfMonth(dv[i]));
    }
    return ndates;
}

//' @rdname adjust
// [[Rcpp::export]]
Rcpp::DateVector adjust_cpp(Rcpp::DateVector dates, int bdc=0) {
    ql::Calendar cal = gblcal.getCalendar();
    ql::BusinessDayConvention bdcval = getBusinessDayConvention(bdc);
    int n = dates.size();
    Rcpp::DateVector adjusted(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        adjusted[i] = Rcpp::qlDate2Rcpp(cal.adjust(dv[i], bdcval));
    }
    return adjusted;
}

//' @rdname advanceUnits
// [[Rcpp::export]]
Rcpp::DateVector advanceUnits_cpp(Rcpp::DateVector dates, int n, int unit,
                                  int bdc, bool emr) {
    ql::Calendar cal = gblcal.getCalendar();
    ql::BusinessDayConvention bdc_ = getBusinessDayConvention(bdc);
    ql::TimeUnit tu = getTimeUnit(unit);
    int ndays = dates.size();
    Rcpp::DateVector adv(ndays);
    std::vector<ql::Date> odv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<ndays; i++) {
        ql::Date nd = cal.advance(odv[i], n, tu, bdc_, (emr == 1) ? true : false);
        adv[i] = Rcpp::qlDate2Rcpp(nd);
    }
    return adv;
}


//' Compute the number of business days between dates
//'
//' This function takes two vectors of start and end dates and returns another
//' vector of the number of business days between each corresponding date pair
//' according to the active calendar.
//'
//' @title Compute number of business dates between calendar dates
//' @param from A Date vector with interval start dates
//' @param to A Date vector with interval end dates
//' @param includeFirst A boolean indicating if the start date is included, default
//' is \sQuote{TRUE}
//' @param includeLast A boolean indicating if the end date is included, default
//' is \sQuote{FALSE}
//' @return A numeric vector with the number of business dates between the
//' corresponding date pair
//' @examples
//' businessDaysBetween(Sys.Date() + 0:6, Sys.Date() + 3 + 0:6)
// [[Rcpp::export]]
Rcpp::NumericVector businessDaysBetween(Rcpp::DateVector from, Rcpp::DateVector to,
                                        bool includeFirst=true, bool includeLast=false) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = from.size();
    Rcpp::NumericVector between(n);
    std::vector<ql::Date> fdv = Rcpp::as< std::vector<ql::Date> >(from);
    std::vector<ql::Date> tdv = Rcpp::as< std::vector<ql::Date> >(to);
    for (auto i=0; i<n; i++) {
        between[i] = cal.businessDaysBetween(fdv[i], tdv[i], includeFirst, includeLast);
    }
    return between;
}

//' Compute the number of holidays (or business days) between two dates
//'
//' This function takes a start and end date and returns a vector of holidays
//' (or business days) between them according to the active calendar.
//'
//' @title Compute holidays or business days
//' @param from A Date object with the start date
//' @param to A Date object with the end date
//' @param includeWeekends A boolean indicating if weekends should be included, default
//' is \sQuote{FALSE}
//' @return A Date vector with holidays or business days between the given dates
//' @examples
//' getHolidays(Sys.Date(), Sys.Date() + 30)
// [[Rcpp::export]]
Rcpp::DateVector getHolidays(Rcpp::Date from, Rcpp::Date to, bool includeWeekends=false) {
    ql::Calendar cal = gblcal.getCalendar();
    std::vector<ql::Date> holidays = cal.holidayList(Rcpp::as<ql::Date>(from),
                                                     Rcpp::as<ql::Date>(to), includeWeekends);
    int n = holidays.size();
    Rcpp::DateVector dv(n);
    for (auto i=0; i<n; i++) {
        dv[i] = Rcpp::qlDate2Rcpp(holidays[i]);
    }
    return dv;
}

//' @rdname getHolidays
// [[Rcpp::export]]
Rcpp::DateVector getBusinessDays(Rcpp::Date from, Rcpp::Date to) {
    ql::Calendar cal = gblcal.getCalendar();
    std::vector<ql::Date> holidays = cal.businessDayList(Rcpp::as<ql::Date>(from),
                                                         Rcpp::as<ql::Date>(to));
    int n = holidays.size();
    Rcpp::DateVector dv(n);
    for (auto i=0; i<n; i++) {
        dv[i] = Rcpp::qlDate2Rcpp(holidays[i]);
    }
    return dv;
}
