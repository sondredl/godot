all:
	scons platform=linuxbsd


pragmance:
	find . -name *.h -exec sed -i '/#ifndef/d; /#define/d; /#endif \/\/.*_H/d; 1i#pragma once' {} +
