from conans import ConanFile, CMake, tools, __version__ as conan_version

assert conan_version >= tools.Version('1.60.0'), 'Conan version is too old.'


class Qt6CmdAppConan(ConanFile):
    name = 'qt6-cmd-app'
    version = '0.0.0'
    generators = 'cmake'

    settings = "os", "arch", "compiler", "build_type"
    options = {
        'shared': [True, False],
    }
    default_options = {
        'shared': True,
    }

    exports_sources = (
        'CMakeLists.txt',
        'main.cpp',
    )

    requires = 'qt/6.4.0@nap/devel'

    def build(self):
        self.cmake.build()

    def package(self):
        self.cmake.install()

    @property
    def cmake(self):
        cmake = CMake(self, generator='Ninja', set_cmake_flags=True)
        cmake.configure()
        return cmake
