
#ifndef qlcal_date_wrappers_h
#define qlcal_date_wrappers_h

#ifndef QL_HIGH_RESOLUTION_DATE
  #define QL_HIGH_RESOLUTION_DATE
#endif
#include <ql/quantlib.hpp>

#include <Rcpp.h>

// define template specialisations for as and wrap
namespace Rcpp {

    namespace bg = boost::gregorian;
    namespace bpt = boost::posix_time;

    static const unsigned int QLtoJan1970Offset = 25569;  	// Offset to R / Unix epoch

    inline unsigned int getQLtoJan1970offset(void) { return QLtoJan1970Offset; }

    template <> QuantLib::Date as(Rcpp::Date dt) {
        return QuantLib::Date(static_cast<int>(dt.getDate()) + QLtoJan1970Offset);
    }
    template <> QuantLib::Date as(Rcpp::Datetime dt) {
        const bpt::ptime pt(bg::date(dt.getYear(), dt.getMonth(), dt.getDay()),
                            bpt::time_duration(dt.getHours(), dt.getMinutes(),
                                               dt.getSeconds(), dt.getMicroSeconds()*1000.0));
        return QuantLib::Date(pt);
    }

    template <> SEXP wrap(const QuantLib::Date &d) {
        double dt = static_cast<double>(d.serialNumber()); // QL::BigInteger can cast to double
        return Rcpp::wrap(Rcpp::Date(dt - QLtoJan1970Offset));
    }

    // non-intrusive extension via template specialisation
    template <> std::vector<QuantLib::Date> as(SEXP dtvecsexp) {
        Rcpp::DateVector dtvec(dtvecsexp);
        int n = dtvec.size();
        std::vector<QuantLib::Date> dates(n);
        for (int i = 0; i<n; i++){
            dates[i] = QuantLib::Date(static_cast<int>(Rcpp::Date(dtvec[i]).getDate()) + QLtoJan1970Offset);
        }
        return dates;
    }

    // QL to Rcpp without SEXP in the middle -- outside of as<> and wrap
    inline Rcpp::Date qlDate2Rcpp(QuantLib::Date d) {
        // QL::BigInteger can cast to double, safer from overflow than R's integer
        return Rcpp::Date(static_cast<double>(d.serialNumber()) - QLtoJan1970Offset);
    }

    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const std::vector<QuantLib::Date> &dvec) {
        int n = dvec.size();
        Rcpp::DateVector dtvec(n);
        for (int i = 0; i<n; i++) {
            dtvec[i] = qlDate2Rcpp(dvec[i]);
        }
        return Rcpp::wrap(dtvec);
    }

}

#endif
