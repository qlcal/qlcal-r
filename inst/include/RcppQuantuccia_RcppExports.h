// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_RcppQuantuccia_RCPPEXPORTS_H_GEN_
#define RCPP_RcppQuantuccia_RCPPEXPORTS_H_GEN_

#include "RcppQuantuccia_types.h"
#include <Rcpp.h>

namespace RcppQuantuccia {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("RcppQuantuccia", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in RcppQuantuccia");
            }
        }
    }

    inline void setCalendar(std::string calstr) {
        typedef SEXP(*Ptr_setCalendar)(SEXP);
        static Ptr_setCalendar p_setCalendar = NULL;
        if (p_setCalendar == NULL) {
            validateSignature("void(*setCalendar)(std::string)");
            p_setCalendar = (Ptr_setCalendar)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_setCalendar");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_setCalendar(Shield<SEXP>(Rcpp::wrap(calstr)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
    }

    inline std::string getName() {
        typedef SEXP(*Ptr_getName)();
        static Ptr_getName p_getName = NULL;
        if (p_getName == NULL) {
            validateSignature("std::string(*getName)()");
            p_getName = (Ptr_getName)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_getName");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getName();
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<std::string >(rcpp_result_gen);
    }

    inline std::string getId() {
        typedef SEXP(*Ptr_getId)();
        static Ptr_getId p_getId = NULL;
        if (p_getId == NULL) {
            validateSignature("std::string(*getId)()");
            p_getId = (Ptr_getId)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_getId");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getId();
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<std::string >(rcpp_result_gen);
    }

    inline Rcpp::Date advanceDate(Rcpp::Date rd, int days = 0) {
        typedef SEXP(*Ptr_advanceDate)(SEXP,SEXP);
        static Ptr_advanceDate p_advanceDate = NULL;
        if (p_advanceDate == NULL) {
            validateSignature("Rcpp::Date(*advanceDate)(Rcpp::Date,int)");
            p_advanceDate = (Ptr_advanceDate)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_advanceDate");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_advanceDate(Shield<SEXP>(Rcpp::wrap(rd)), Shield<SEXP>(Rcpp::wrap(days)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::Date >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isBusinessDay(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isBusinessDay)(SEXP);
        static Ptr_isBusinessDay p_isBusinessDay = NULL;
        if (p_isBusinessDay == NULL) {
            validateSignature("Rcpp::LogicalVector(*isBusinessDay)(Rcpp::DateVector)");
            p_isBusinessDay = (Ptr_isBusinessDay)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_isBusinessDay");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isBusinessDay(Shield<SEXP>(Rcpp::wrap(dates)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isHoliday(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isHoliday)(SEXP);
        static Ptr_isHoliday p_isHoliday = NULL;
        if (p_isHoliday == NULL) {
            validateSignature("Rcpp::LogicalVector(*isHoliday)(Rcpp::DateVector)");
            p_isHoliday = (Ptr_isHoliday)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_isHoliday");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isHoliday(Shield<SEXP>(Rcpp::wrap(dates)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isWeekend(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isWeekend)(SEXP);
        static Ptr_isWeekend p_isWeekend = NULL;
        if (p_isWeekend == NULL) {
            validateSignature("Rcpp::LogicalVector(*isWeekend)(Rcpp::DateVector)");
            p_isWeekend = (Ptr_isWeekend)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_isWeekend");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isWeekend(Shield<SEXP>(Rcpp::wrap(dates)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isEndOfMonth(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isEndOfMonth)(SEXP);
        static Ptr_isEndOfMonth p_isEndOfMonth = NULL;
        if (p_isEndOfMonth == NULL) {
            validateSignature("Rcpp::LogicalVector(*isEndOfMonth)(Rcpp::DateVector)");
            p_isEndOfMonth = (Ptr_isEndOfMonth)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_isEndOfMonth");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isEndOfMonth(Shield<SEXP>(Rcpp::wrap(dates)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::DateVector getEndOfMonth(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_getEndOfMonth)(SEXP);
        static Ptr_getEndOfMonth p_getEndOfMonth = NULL;
        if (p_getEndOfMonth == NULL) {
            validateSignature("Rcpp::DateVector(*getEndOfMonth)(Rcpp::DateVector)");
            p_getEndOfMonth = (Ptr_getEndOfMonth)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_getEndOfMonth");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getEndOfMonth(Shield<SEXP>(Rcpp::wrap(dates)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::DateVector >(rcpp_result_gen);
    }

    inline Rcpp::DateVector adjust_cpp(Rcpp::DateVector dates, int bdc = 0) {
        typedef SEXP(*Ptr_adjust_cpp)(SEXP,SEXP);
        static Ptr_adjust_cpp p_adjust_cpp = NULL;
        if (p_adjust_cpp == NULL) {
            validateSignature("Rcpp::DateVector(*adjust_cpp)(Rcpp::DateVector,int)");
            p_adjust_cpp = (Ptr_adjust_cpp)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_adjust_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_adjust_cpp(Shield<SEXP>(Rcpp::wrap(dates)), Shield<SEXP>(Rcpp::wrap(bdc)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::DateVector >(rcpp_result_gen);
    }

    inline Rcpp::DateVector advanceUnits_cpp(Rcpp::DateVector dates, int n, int unit, int bdc, bool emr) {
        typedef SEXP(*Ptr_advanceUnits_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_advanceUnits_cpp p_advanceUnits_cpp = NULL;
        if (p_advanceUnits_cpp == NULL) {
            validateSignature("Rcpp::DateVector(*advanceUnits_cpp)(Rcpp::DateVector,int,int,int,bool)");
            p_advanceUnits_cpp = (Ptr_advanceUnits_cpp)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_advanceUnits_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_advanceUnits_cpp(Shield<SEXP>(Rcpp::wrap(dates)), Shield<SEXP>(Rcpp::wrap(n)), Shield<SEXP>(Rcpp::wrap(unit)), Shield<SEXP>(Rcpp::wrap(bdc)), Shield<SEXP>(Rcpp::wrap(emr)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::DateVector >(rcpp_result_gen);
    }

    inline Rcpp::NumericVector businessDaysBetween(Rcpp::DateVector from, Rcpp::DateVector to, bool includeFirst = true, bool includeLast = false) {
        typedef SEXP(*Ptr_businessDaysBetween)(SEXP,SEXP,SEXP,SEXP);
        static Ptr_businessDaysBetween p_businessDaysBetween = NULL;
        if (p_businessDaysBetween == NULL) {
            validateSignature("Rcpp::NumericVector(*businessDaysBetween)(Rcpp::DateVector,Rcpp::DateVector,bool,bool)");
            p_businessDaysBetween = (Ptr_businessDaysBetween)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_businessDaysBetween");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_businessDaysBetween(Shield<SEXP>(Rcpp::wrap(from)), Shield<SEXP>(Rcpp::wrap(to)), Shield<SEXP>(Rcpp::wrap(includeFirst)), Shield<SEXP>(Rcpp::wrap(includeLast)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::NumericVector >(rcpp_result_gen);
    }

    inline Rcpp::DateVector getHolidays(Rcpp::Date from, Rcpp::Date to, bool includeWeekends = false) {
        typedef SEXP(*Ptr_getHolidays)(SEXP,SEXP,SEXP);
        static Ptr_getHolidays p_getHolidays = NULL;
        if (p_getHolidays == NULL) {
            validateSignature("Rcpp::DateVector(*getHolidays)(Rcpp::Date,Rcpp::Date,bool)");
            p_getHolidays = (Ptr_getHolidays)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_getHolidays");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getHolidays(Shield<SEXP>(Rcpp::wrap(from)), Shield<SEXP>(Rcpp::wrap(to)), Shield<SEXP>(Rcpp::wrap(includeWeekends)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::DateVector >(rcpp_result_gen);
    }

    inline Rcpp::DateVector getBusinessDays(Rcpp::Date from, Rcpp::Date to) {
        typedef SEXP(*Ptr_getBusinessDays)(SEXP,SEXP);
        static Ptr_getBusinessDays p_getBusinessDays = NULL;
        if (p_getBusinessDays == NULL) {
            validateSignature("Rcpp::DateVector(*getBusinessDays)(Rcpp::Date,Rcpp::Date)");
            p_getBusinessDays = (Ptr_getBusinessDays)R_GetCCallable("RcppQuantuccia", "_RcppQuantuccia_getBusinessDays");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getBusinessDays(Shield<SEXP>(Rcpp::wrap(from)), Shield<SEXP>(Rcpp::wrap(to)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::DateVector >(rcpp_result_gen);
    }

}

#endif // RCPP_RcppQuantuccia_RCPPEXPORTS_H_GEN_
