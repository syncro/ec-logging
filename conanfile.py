from conans import ConanFile
import os
from conans.tools import download
from conans.tools import unzip
from conans import CMake


class GTestConan(ConanFile):
    name = "ec-logging"
    version = "master"
    ZIP_FOLDER_NAME = "%s-%s" % (name, version)
    generators = "cmake"
    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False]}
    default_options = "shared=True"
    url="http://github.com/syncro/%s" % name
    license="https://github.com/syncro/%s/blob/master/COPYING" % name
    exports = ["CMakeLists.txt", "include/*"]

    def source(self):
        zip_name = "%s-%s.zip" % (self.name, self.version)
        url = "https://github.com/syncro/%s/archive/master.zip" % self.name
        download(url, zip_name)
        unzip(zip_name)
        os.system("cp -R %s-%s/* ." % (self.name, self.version)) # hack to build as dependency
        os.unlink(zip_name)

    def build(self):
        cmake = CMake(self.settings)
        try:
            os.makedirs("_build")
        except OSError:
            pass

        cd_build = "cd _build"
        shared = "-DBUILD_SHARED_LIBS=1" if self.options.shared else ""

        self.run('%s && cmake .. %s %s' % (cd_build, cmake.command_line, shared))
        self.run("%s && cmake --build . %s" % (cd_build, cmake.build_config))

    def package(self):
        self.copy(pattern="*", dst="include", src="include", keep_path=True)

        # Copying static and dynamic libs
        self.copy(pattern="*.a", dst="lib", src=".", keep_path=False)
        self.copy(pattern="*.lib", dst="lib", src=".", keep_path=False)
        self.copy(pattern="*.dll", dst="bin", src=".", keep_path=False)
        self.copy(pattern="*.so*", dst="lib", src=".", keep_path=False)
        self.copy(pattern="*.dylib*", dst="lib", src=".", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = [self.name]
        if self.settings.os == "Linux":
            self.cpp_info.libs.append("pthread")
