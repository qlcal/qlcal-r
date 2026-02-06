
print.qlcalendar <- function(x, ...) {
    cat("<qlcalendar object for '", getName(x), "'>\n", sep="")
    invisible(x)
}
