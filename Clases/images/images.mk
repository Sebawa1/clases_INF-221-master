# images.mk
#
# Copyright (c) 2017, 2020 Horst H. von Brand
# Bajo licencia MIT. Vea LICENSE-MIT para detalles

ALL	+=
IMAGES	+= $(IPDF)
CLEAN	+=
CLOBBER += $(IPDF)

RUNGE_PLOT := images/runge.pdf \
		$(foreach n, 4 6 8 10, images/runge-${n}.pdf)
RUNGE_ERR  := images/runge-error.pdf

CHBV_PLOT  := $(foreach n, 4 6 8 10, images/chebyshev-${n}.pdf)
CHBV_ERR   := images/chebyshev-error.pdf

IPDF	   := $(RUNGE_PLOT) $(RUNGE_ERR) \
	      $(CHBV_PLOT) $(CHBV_ERR)

$(RUNGE_PLOT): images/runge-plot
	cd images; ./runge-plot

$(RUNGE_ERR): images/runge-err
	cd images; ./runge-err

$(CHBV_PLOT): images/chebyshev-plot
	cd images; ./chebyshev-plot

$(CHBV_ERR): images/chebyshev-err
	cd images; ./chebyshev-err
