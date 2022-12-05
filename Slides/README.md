README
======

These slides are modeled on the main class notes.  They use the
[`axessibility`][1] LaTeX package, officially included in the TeXlive
distribution, but not included in Fedora up to 32 (it is available for
Fedora 33)) to make the resulting PDF more palatable for screen
readers/Braile printers.  If you don't need any of this, just comment
the package load out.  The latest is [version][2].  It
requires the `tagpdf` LaTeX package.  To build and install, clone the
repository and to install it for your account give the commands:

```
pdflatex axessibility.ins
pdflatex axessibility.dtx

mkdir -p ~/texmf/tex/latex/axessibility
cp axessibility.sty ~/texmf/tex/latex/axessibility
mkdir -p ~/texmf/doc/latex/axessibility
cp axessibility.pdf ~/texmf/tex/latex/axessibility
```

For system-wide install on Fedora prior to 33 the last four commands
would be:

```
mkdir -p /usr/share/texlive/texmf-local/tex/latex/axessibility
cp axessibility.sty /usr/share/texlive/texmf-local/tex/latex/axessibility
mkdir -p /usr/share/texlive/texmf-local/doc/latex/axessibility
cp axessibility.pdf /usr/share/texlive/texmf-local/doc/latex/axessibility
```

For other Linux distributions you are on your own.

[1]: https://ctan.org/pkg/axessibility
[2]: https://github.com/integr-abile/axessibility.git