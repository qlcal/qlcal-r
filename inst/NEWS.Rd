\name{NEWS}
\title{News for Package \pkg{QlCal}}
\newcommand{\ghpr}{\href{https://github.com/qlcal/qlcal-r/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/qlcal/qlcal-r/issues/#1}{##1}}

\section{Changes in version 0.0.16 (2025-07-23)}{
  \itemize{
    \item Synchronized with QuantLib 1.39 released today
    \item Calendar updates for Israel, minor utility functions update
    \item Minor package maintenance updates
  }
}

\section{Changes in version 0.0.15 (2025-04-23)}{
  \itemize{
    \item Synchronized with QuantLib 1.38 released today
    \item Calendar updates for China, Hongkong, Thailand
    \item Minor continuous integration update
  }
}

\section{Changes in version 0.0.14 (2025-01-23)}{
  \itemize{
    \item Synchronized with QuantLib 1.37 released two days ago
    \item Calendar updates for United States and New Zealand
    \item The \code{demo/} file is now in \code{inst/examples/}
  }
}

\section{Changes in version 0.0.13 (2024-10-15)}{
  \itemize{
    \item Synchronized with QuantLib 1.36 released yesterday
    \item Calendar updates for South Korea and Poland
  }
}

\section{Changes in version 0.0.12 (2024-07-22)}{
  \itemize{
    \item Synchronized with QuantLib 1.35 released today
    \item Calendar updates for Chile, India, United States, Brazil
  }
}

\section{Changes in version 0.0.11 (2024-04-27)}{
  \itemize{
    \item Synchronized with QuantLib 1.34
    \item Calendar updates for Brazil, India, Singapore, South Africa,
    Thailand, United States
    \item Minor continuous integration update
  }
}

\section{Changes in version 0.0.10 (2024-01-24)}{
  \itemize{
    \item Synchronized with QuantLib 1.33
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
