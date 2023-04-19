
suppressMessages({
    library(qlcal) 		# holiday calculation
    library(xts)        # to glue day-indexed time series via cbind
})

## returns an xts series for given (US) holiday in current year
makeHol <- function(cal) {
    setCalendar(paste0("UnitedStates/", cal))
    hols <- getHolidays(as.Date(format(Sys.Date(), "%Y-01-01")),
                        as.Date(format(Sys.Date(), "%Y-12-31")))
    x <- xts(rep(TRUE, length(h)), order.by=hols)
    colnames(x) <- cal
    x
}

## see R/calendars.R in qlcal, we prepend 'UnitedStates/' in makeHol()
cals <- c("LiborImpact", "NYSE", "GovernmentBond", "NERC", "FederalReserve")
print(Reduce(cbind, Map(makeHol, cals)))
