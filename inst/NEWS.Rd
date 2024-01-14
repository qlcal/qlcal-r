\name{NEWS}
\title{News for Package \pkg{QlCal}}
\newcommand{\ghpr}{\href{https://github.com/qlcal/qlcal-r/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/qlcal/qlcal-r/issues/#1}{##1}}

\section{Changes in version 0.0.9.1 (2024-01-14)}{
  \itemize{
    \item Synchronized with (release candidate of) QuantLib 1.32
  }
}

\section{Changes in version 0.0.9 (2023-11-29)}{
  \itemize{
    \item \code{configure} now uses a new helper script to only set a
    compilation standard when needed for R versions older than 4.2.0
    \item The file \code{RcppExports.cpp} was regenerated to avoid a string
    format warning from R-devel
  }
}

\section{Changes in version 0.0.8 (2023-10-21)}{
  \itemize{
    \item A small set of updates from QuantLib 1.32 have been applied
    \item The explicit C++14 compilation standard has been replaced with
    an implicit one by relying on R (>= 4.2.0)
    \item Synchronized with QuantLib 1.32
  }
}

\section{Changes in version 0.0.7 (2023-07-19)}{
  \itemize{
    \item Updates, extensions and corrections to calendars from South Korea,
    Hong Kong, Singapore, India, Taiwan, South Africa, Denmark and Finland
    from QuantLib 1.31
    \item Added support for UnitedStates/SOFR calendar
  }
}

\section{Changes in version 0.0.6 (2023-05-24)}{
  \itemize{
    \item Several calendars (India, Singapore, South Africa, South Korea)
    updated with post-QuantLib 1.30 changes (Sebastian Schmidt in \ghpr{6})
    \item Three now-used scheduled files were removed (Dirk in \ghpr{7}))
    \item A number of non-calendaring files used were synchronised with the
    current QuantLib repo (Dirk in \ghpr{8})
  }
}

\section{Changes in version 0.0.5 (2023-04-19)}{
  \itemize{
    \item Calendars routines for Australia, Denmark, New Zealand, Turkey and
    the US have been updated from QuantLib 1.30.
    \item Support for 'Australia/ASX' has been added.
    \item Added demo showing all US holidays in current year
  }
}

\section{Changes in version 0.0.4 (2023-01-11)}{
  \itemize{
    \item The \code{advanceDate{}} function can now selects a business day
    convention, a time unit and an end-of-month convention
    \item Calendars routines for Australia, China, South Africa, UK, US have
    been updated to current versions from QuantLib 1.29.
  }
}

\section{Changes in version 0.0.3 (2022-10-19)}{
  \itemize{
    \item Correct the \code{isBusinessDay()} functionality (Fixes \ghit{2})
    \item Update Australia and Saudi Arabia calendars from QuantLib 1.27
    \item Update United Kingdom calendar from QuantLib 1.28
    \item Convert one source file to utf-8 to appease \code{clang-15}
  }
}

\section{Changes in version 0.0.2 (2022-01-21)}{
  \itemize{
    \item Further minimize set of files needed for calendaring
    \item Update China calendar from QuantLib 1.25 release
  }
}

\section{Changes in version 0.0.1 (2021-12-07)}{
  \itemize{
    \item Initial release
  }
}
