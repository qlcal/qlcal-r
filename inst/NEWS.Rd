\name{NEWS}
\title{News for Package \pkg{QlCal}}
\newcommand{\ghpr}{\href{https://github.com/qlcal/qlcal-r/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/qlcal/qlcal-r/issues/#1}{##1}}

\section{Changes in version 0.0.6 (2023-05-24)}{
  \itemize{
    \item Several calendars (India, Singapore, South Africa, South Korea)
    updated with post-QuantLib 1.3.0 changes (Sebastian Schmidt in \ghpr{6})
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
