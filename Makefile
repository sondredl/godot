all:
	scons platform=linuxbsd tests=yes
	cd godot-cpp && make linux64

debug:
	scons -j32 platform=linuxbsd linker=mold optimize=none fast_unsafe=yes progress=no debug_symbols=yes builtin_embree=no builtin_enet=no builtin_freetype=no builtin_graphite=no builtin_harfbuzz=no builtin_libogg=no builtin_libpng=no builtin_libtheora=no builtin_libvorbis=no builtin_libwebp=no builtin_mbedtls=yes builtin_pcre2=no builtin_zlib=no builtin_zstd=no scu_build=all tests=yes

mac:
	scons platform=macos arch=arm64
	cd godot-cpp && scons  platform=macos
analyze:
	# scan-build -o static_analysis scons platform=linuxbsd
	# scan-build -o static_analysis  -plist scons platform=linuxbsd
	# scan-build -o static_analysis scons
	# scan-build --analyze scons platform=linuxbsd
	scons platform=linuxbsd tests=yes target=template_debug	ANALYZE=1

test:
	scons tests=yes
	# ./bin/godot.linuxbsd.editor.x86_64 --test >> testResults.txt
	./bin/godot.linuxbsd.editor.x86_64 --test 
