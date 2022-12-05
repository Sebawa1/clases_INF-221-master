# Makefile
#
# Copyright (c) 2020 Horst H. von Brand
# Bajo licencia MIT. Vea LICENSE-MIT para detalles

dist: Clases/CLASS-VERSION-FILE
	@rm -rf $(CLASS_TARNAME) $(CLASS_TARNAME).tar $(CLASS_TARNAME).tar.gz
	git archive --format=tar \
	    --prefix=$(CLASS_TARNAME)/ HEAD^{tree} . > $(CLASS_TARNAME).tar
	@mkdir -p $(CLASS_TARNAME)
	@echo $(CLASS_VERSION) > $(CLASS_TARNAME)/version
	@tar rf $(CLASS_TARNAME).tar $(CLASS_TARNAME)/version
	@rm -rf $(CLASS_TARNAME)
	@gzip -9 $(CLASS_TARNAME).tar

Clases/CLASS-VERSION-FILE: FORCE
	@cd Clases; ./CLASS-VERSION-GEN

-include Clases/CLASS-VERSION-FILE

CLASS_TARNAME = INF-221-$(CLASS_VERSION)

.PHONY: dist FORCE
