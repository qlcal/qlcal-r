
rver <- getRversion()
if (rver < "4.2.0") {
    ## for R versions prior to 4.2.0 we need to set the standard
    cxxstd <- "CXX_STD = CXX14"
} else {
    ## for R 4.2.0 C++14 is standard, for R 4.3.0 it is C++17 so no need
    cxxstd <- "#CXX_STD = CXX14"
}
win <- if (Sys.info()[["sysname"]] == "Windows") ".win" else ""
infile <- file.path("src", paste0("Makevars", win, ".in"))
outfile <- file.path("src", paste0("Makevars", win))
lines <- readLines(infile)
lines <- gsub("@CXXSTD@", cxxstd, lines)
writeLines(lines, outfile)
