#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "qlcal_types.h"
#include "qlcal_declarations.h"
#include "qlcal_as_wrap.h"

// [[Rcpp::interfaces(r, cpp)]]

namespace ql = QuantLib;

extern QlCal::CalendarContainer gblcal;

template <typename T> Rcpp::XPtr<T> make_xptr(T* p) {
    return Rcpp::XPtr<T>(p);
}

// [[Rcpp::export]]
Rcpp::XPtr<QlCal::CalendarContainer> getXPtr(std::string calstr) {
    auto p = make_xptr(new QlCal::CalendarContainer);
    p->setCalendar(calstr);
    p.attr("class") = Rcpp::CharacterVector::create("qlcalendar", "externalptr");
    return p;
}

// [[Rcpp::export]]
bool isBusinessDate(Rcpp::Nullable<Rcpp::Date> date = R_NilValue,
                    Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    Rcpp::Date d;
    if (date.isNull()) {
        const std::time_t t_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::ostringstream oss;
        oss << std::put_time(std::localtime(&t_c), "%Y-%m-%d");
        d = Rcpp::Date(oss.str());
    } else {
        d = Rcpp::Date(date);
    }
    Rcpp::Rcout << "d is " << d << std::endl;
    ql::Date qd = Rcpp::as<ql::Date>(d);

    ql::Calendar cal;
    if (xp.isNotNull()) {
        Rcpp::XPtr<QlCal::CalendarContainer> p = Rcpp::XPtr<QlCal::CalendarContainer>(xp);
        cal = p->getCalendar();
    } else {
        QlCal::CalendarContainer calct;
        cal = calct.getCalendar();
    }
    return cal.isBusinessDay(qd);
}

//' Get calendar name or id
//'
//' This function returns the corresponding (full) name (as in the underlying
//' implementationclass) or identification string (used to select it) of the
//' current calendar.
//'
//' @title Get calendar name, or id
//' @return A string with the calendar name
//' @examples
//' getName()
// [[Rcpp::export]]
std::string getName(Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    if (xp.isNotNull()) {
        Rcpp::XPtr<QlCal::CalendarContainer> p = Rcpp::XPtr<QlCal::CalendarContainer>(xp);
        return p->getName();
    } else {
        return gblcal.getName();
    }
}

//' @rdname getName
// [[Rcpp::export]]
std::string getId(Rcpp::Nullable<Rcpp::XPtr<QlCal::CalendarContainer>> xp = R_NilValue) {
    if (xp.isNotNull()) {
        Rcpp::XPtr<QlCal::CalendarContainer> p = Rcpp::XPtr<QlCal::CalendarContainer>(xp);
        return p->getId();
    } else {
        return gblcal.getId();
    }
}
