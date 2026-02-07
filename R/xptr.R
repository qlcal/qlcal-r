
print.qlcalendar <- function(x, ...) {
    cat("<qlcal calendar object '", getId(x), "' aka '", getName(x), "'>\n", sep="")
    invisible(x)
}
