
#ifndef qlcal_declarations_h
#define qlcal_declarations_h

#ifndef QL_HIGH_RESOLUTION_DATE
  #define QL_HIGH_RESOLUTION_DATE
#endif
#include <ql/quantlib.hpp>

QuantLib::BusinessDayConvention getBusinessDayConvention(const int n);
QuantLib::BusinessDayConvention getBusinessDayConvention(const std::string& s);
QuantLib::Frequency getFrequency(const int n);
QuantLib::TimeUnit getTimeUnit(const int n);
QuantLib::TimeUnit getTimeUnit(const std::string& s);

#endif
