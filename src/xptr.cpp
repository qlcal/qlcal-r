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
