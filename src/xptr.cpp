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

//' Get new calendar
//'
//' This function returns an external pointer, classed as small S3 helper class,
//' to a new QuantLib Calendar object identified by the calendar string.
//'
//' @title Get new calendar objectb
//' @param calstr Character variable identifying desired calendar
//' @return A external pointer classed as S3 class 'qlcalendar'
//' @examples
//' xp <- getCalendar("UnitedStates/NYSE")
//' xp  # invokes the print method
// [[Rcpp::export]]
Rcpp::XPtr<QlCal::CalendarContainer> getCalendar(std::string calstr) {
    auto p = make_xptr(new QlCal::CalendarContainer);
    p->setCalendar(calstr);
    p.attr("class") = Rcpp::CharacterVector::create("qlcalendar", "externalptr");
    return p;
}

//' Get calendar name or id
//'
//' This function returns the corresponding (full) name (as in the underlying
//' implementationclass) or identification string (used to select it) of the
//' current calendar.
//'
//' @title Get calendar name, or id
//' @param xp A calendar object created via \code{getCalendar}
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
