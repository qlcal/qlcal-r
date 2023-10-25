
## qlcal-r: QuantLib Calendaring for R

[![CI](https://github.com/qlcal/qlcal-r/workflows/ci/badge.svg)](https://github.com/qlcal/qlcal-r/actions?query=workflow%3Aci)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](http://www.gnu.org/licenses/gpl-2.0.html)
[![Last Commit](https://img.shields.io/github/last-commit/qlcal/qlcal-r)](https://github.com/qlcal/qlcal-r)
[![CRAN](https://www.r-pkg.org/badges/version/qlcal)](https://cran.r-project.org/package=qlcal)
[![r-universe](https://qlcal.r-universe.dev/badges/qlcal)](https://qlcal.r-universe.dev/qlcal)
[![Dependencies](https://tinyverse.netlify.com/badge/qlcal)](https://cran.r-project.org/package=qlcal)
[![Downloads](https://cranlogs.r-pkg.org/badges/qlcal?color=brightgreen)](https://www.r-pkg.org/pkg/qlcal)

`qlcal` brings the calendaring functionality from the [QuantLib](https://www.quantlib.org) project to R.

### Motivation

`qlcal` lets us access various global (exchange or settlement) calendars.
Here is a quick example for the NYSE in 2022 where Juneteenth is making a first appearance as the most recently added federal holiday:

```r
> library(qlcal)
> setCalendar("UnitedStates/NYSE")
> getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))
[1] "2022-01-17" "2022-02-21" "2022-04-15" "2022-05-30" "2022-06-20"
[6] "2022-07-04" "2022-09-05" "2022-11-24" "2022-12-26"
>
```

### Brief History

This package started as an integration of the (somewhat experimental) [Quantuccia](https://github.com/pcaspers/Quantuccia) package (see next section) to R by means of [Rcpp](https://github.com/RcppCore/Rcpp) in package [RcppQuantuccia](https://github.com/eddelbuettel/rcppquantuccia).
But [Quantuccia](https://github.com/pcaspers/Quantuccia) did not continue beyond its initial proof of concept.
So as of RcppQuantuccia release 0.0.5, we have refocused it on an _even smaller subset_ of
[QuantLib](https://github.com/lballabio/quantlib): just the calendaring.  So code for pricers, math, models, schedules, ... that was in [Quantuccia](https://github.com/pcaspers/Quantuccia) has been removed. The calendaring, along with all its support code, is now current with the current
[QuantLib](https://github.com/lballabio/quantlib) release which, as of this writing, is 1.24.

Going forward, the idea is to regroup the QuantLib calendaring functionality in a small and self-contained library `qlcal`, and provide frontends such as this R package.

### Longer Example

Here we examine holiday lists for given calendars, specified by country and possibly exchange:

```r
R> library(qlcal)
R> fromD <- as.Date("2017-01-01")
R> toD <- as.Date("2017-12-31")
R> getHolidays(fromD, toD)        # default calender ie TARGET
[1] "2017-04-14" "2017-04-17" "2017-05-01" "2017-12-25" "2017-12-26"
R> setCalendar("UnitedStates")
R> getHolidays(fromD, toD)        # US aka US::Settlement
[1] "2017-01-02" "2017-01-16" "2017-02-20" "2017-05-29" "2017-07-04" "2017-09-04"
[7] "2017-10-09" "2017-11-10" "2017-11-23" "2017-12-25"
R> setCalendar("UnitedStates::NYSE")
R> getHolidays(fromD, toD)        # US New York Stock Exchange
[1] "2017-01-02" "2017-01-16" "2017-02-20" "2017-04-14" "2017-05-29" "2017-07-04"
[7] "2017-09-04" "2017-11-23" "2017-12-25"
R>
```

This shows the difference between the default US settlement calendar and the NYSE calendar
which we selected explicitly.

As all calendars are now supported (and are listed in a convenience vector `calendars`):

```r
> library(qlcal)
> calendars
 [1] "TARGET"                         "UnitedStates"
 [3] "UnitedStates/LiborImpact"       "UnitedStates/NYSE"
 [5] "UnitedStates/GovernmentBond"    "UnitedStates/NERC"
 [7] "UnitedStates/FederalReserve"    "Argentina"
 [9] "Australia"                      "Austria"
[11] "Austria/Exchange"               "Bespoke"
[13] "Botswana"                       "Brazil"
[15] "Brazil/Exchange"                "Canada"
[17] "Canada/TSX"                     "Chile"
[19] "China"                          "China/IB"
[21] "CzechRepublic"                  "Denmark"
[23] "Finland"                        "France"
[25] "France/Exchange"                "Germany"
[27] "Germany/FrankfurtStockExchange" "Germany/Xetra"
[29] "Germany/Eurex"                  "Germany/Euwax"
[31] "HongKong"                       "Hungary"
[33] "Iceland"                        "India"
[35] "Indonesia"                      "Israel"
[37] "Italy"                          "Italy/Exchange"
[39] "Japan"                          "Mexico"
[41] "NewZealand"                     "Norway"
[43] "Null"                           "Poland"
[45] "Romania"                        "Russia"
[47] "SaudiArabia"                    "Singapore"
[49] "Slovakia"                       "SouthAfrica"
[51] "SouthKorea"                     "SouthKorea/KRX"
[53] "Sweden"                         "Switzerland"
[55] "Taiwan"                         "Thailand"
[57] "Turkey"                         "Ukraine"
[59] "UnitedKingdom"                  "UnitedKingdom/Exchange"
[61] "UnitedKingdom/Metals"           "WeekendsOnly"
>
```

We can then for example quickly count number of holiday per calendar (by computing the length of the returned vector of holidays) and show a shortened print, all in a handful of lines continuing from above

```r
> getHols <- function(cal) {    # simple helper function
+    setCalendar(cal)
+    getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))
+ }
> D <- data.table(calendar=calendars)
> D[ , `:=`(n = length(getHols(calendar)),
+           holidays = paste(format(getHols(calendar),"%d %b"), collapse=",")),
+    by = calendar ]
> D
> D
                       calendar  n                                                                     holidays
 1:                      TARGET  3                                                         15 Apr,18 Apr,26 Dec
 2:                UnitedStates 10        17 Jan,21 Feb,30 May,20 Jun,04 Jul,05 Sep,10 Oct,11 Nov,24 Nov,26 Dec
 3:    UnitedStates/LiborImpact 10        17 Jan,21 Feb,30 May,20 Jun,04 Jul,05 Sep,10 Oct,11 Nov,24 Nov,26 Dec
 4:           UnitedStates/NYSE  9               17 Jan,21 Feb,15 Apr,30 May,20 Jun,04 Jul,05 Sep,24 Nov,26 Dec
 5: UnitedStates/GovernmentBond 11 17 Jan,21 Feb,15 Apr,30 May,20 Jun,04 Jul,05 Sep,10 Oct,11 Nov,24 Nov,26 Dec
---
58:                     Ukraine 10        03 Jan,07 Jan,08 Mar,25 Apr,02 May,09 May,13 Jun,28 Jun,24 Aug,14 Oct
59:               UnitedKingdom  9               03 Jan,15 Apr,18 Apr,02 May,02 Jun,03 Jun,29 Aug,26 Dec,27 Dec
60:      UnitedKingdom/Exchange  9               03 Jan,15 Apr,18 Apr,02 May,02 Jun,03 Jun,29 Aug,26 Dec,27 Dec
61:        UnitedKingdom/Metals  9               03 Jan,15 Apr,18 Apr,02 May,02 Jun,03 Jun,29 Aug,26 Dec,27 Dec
62:                WeekendsOnly  0
>
```

Here we set the year to 2022 as it includes the added US holiday of Juneteenth.

We can also access the calendar 'name' from the underlying (QuantLib Calendar) object:

```r
> D[, name := { setCalendar(calendar); getName() }, by=calendar][, .(calendar,name)]
                       calendar                      name
 1:                      TARGET                    TARGET
 2:                UnitedStates             US settlement
 3:    UnitedStates/LiborImpact      US with Libor impact
 4:           UnitedStates/NYSE   New York stock exchange
 5: UnitedStates/GovernmentBond US government bond market
---
58:                     Ukraine  Ukrainian stock exchange
59:               UnitedKingdom             UK settlement
60:      UnitedKingdom/Exchange     London stock exchange
61:        UnitedKingdom/Metals    London metals exchange
62:                WeekendsOnly             weekends only
>
```


### Installation

The package can be installed from [CRAN](https://cran.r-project.org) via

```r
install.packages("qlcal")
```

or if you prefer non-release development version these can be installed from GitHub via e.g.

```r
remotes::install_github("qlcal/qlcal-r")
```

It only requires `Rcpp` and `BH` both of which are available whereever `R` itself runs.

Note that the package requires C++14 or newer due to the `BH` (_i.e._ Boost) use.  As R nags when we
set `CXX_STD` we switched to requested `R (>= 4.2.0)` where this requirement is implicitly
satisfied.  On an older R version, the `configure` scripts uncomments `CXX_STD = CXX14` in
`src/Makevars` (or `src/Makevars.win`).

### Authors

Dirk Eddelbuettel for the package and integration.

The authors and contributors of QuantLib for the underlying calendaring code.

### License

GPL (>= 2)
