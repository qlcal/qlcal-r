
## qlcal-r: QuantLib Calendaring for R

[![CI](https://github.com/qlcal/qlcal-r/workflows/ci/badge.svg)](https://github.com/qlcal/qlcal-r/actions?query=workflow%3Aci)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](https://www.r-project.org/Licenses/GPL-2)
[![Last Commit](https://img.shields.io/github/last-commit/qlcal/qlcal-r)](https://github.com/qlcal/qlcal-r)
[![CRAN](https://www.r-pkg.org/badges/version/qlcal)](https://cran.r-project.org/package=qlcal)
[![r-universe](https://qlcal.r-universe.dev/badges/qlcal)](https://qlcal.r-universe.dev/qlcal)
[![Dependencies](https://tinyverse.netlify.app/badge/qlcal)](https://cran.r-project.org/package=qlcal)
[![Downloads](https://cranlogs.r-pkg.org/badges/qlcal?color=brightgreen)](https://www.r-pkg.org/pkg/qlcal)

`qlcal` brings the calendaring functionality from the [QuantLib](https://www.quantlib.org) project to R.

### Motivation

`qlcal` lets us access various global (exchange or settlement) calendars.
Here is a quick example for the NYSE:

```r
> library(qlcal)
> setCalendar("UnitedStates/NYSE")     # set the global defaut calendar
> getHolidays(as.Date("2026-01-01"), as.Date("2026-12-31"))
 [1] "2026-01-01" "2026-01-19" "2026-02-16" "2026-04-03" "2026-05-25" "2026-06-19" "2026-07-03"
 [8] "2026-09-07" "2026-11-26" "2026-12-25"
>
```

As of version 0.1.0, we can also create 'calendar objects' that we can pass
to the calendaring functions. Here we keep US and NYSE as the default but
also query Canada and its TSX exchange calendar:

```r
> ca <- getCalendar("Canada/TSX")      # get an override calendar object
> ca
<qlcal calendar object 'Canada/TSX' aka 'TSX'>
> getHolidays(as.Date("2026-01-01"), as.Date("2026-12-31"), xp=ca)
 [1] "2026-01-01" "2026-02-16" "2026-04-03" "2026-05-18" "2026-07-01" "2026-08-03" "2026-09-07"
 [8] "2026-10-12" "2026-12-25" "2026-12-28"
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
> library(qlcal)
> fromD <- as.Date("2026-01-01")
> toD <- as.Date("2026-12-31")
> getHolidays(fromD, toD)        # default calender ie TARGET
[1] "2026-01-01" "2026-04-03" "2026-04-06" "2026-05-01" "2026-12-25"
> us <- getCalendar("UnitedStates")
> getHolidays(fromD, toD, xp=us)   # UnitedStates/Settlement
 [1] "2026-01-01" "2026-01-19" "2026-02-16" "2026-05-25" "2026-06-19" "2026-07-03" "2026-09-07"
 [8] "2026-10-12" "2026-11-11" "2026-11-26" "2026-12-25"
> usny <- getCalendar("UnitedStates/NYSE")
> getHolidays(fromD, toD, xp=usny) # UnitedStates/NYSE
 [1] "2026-01-01" "2026-01-19" "2026-02-16" "2026-04-03" "2026-05-25" "2026-06-19" "2026-07-03"
 [8] "2026-09-07" "2026-11-26" "2026-12-25"
>
```

This shows the difference between the default US settlement calendar and the NYSE calendar
which were selected explicitly (instead of via the global override as above).

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
+    getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"), xp=getCalendar(cal))
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

### See Also

Luigi Ballabio describes [Holidays in
QuantLib](https://www.implementingquantlib.com/2024/07/holidays-in-quantlib.html)
in an introductory article at the [Implementing
QuantLib](https://www.implementingquantlib.com) blog.

### Authors

Dirk Eddelbuettel for the package and integration.

The authors and contributors of QuantLib for the underlying calendaring code.

### License

GPL (>= 2)
