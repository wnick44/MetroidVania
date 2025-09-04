from conan import ConanFile
from conan.tools.scm import Git

from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import cmake_layout

class MetroidVaniaConan(ConanFile):
    name="MetroidVania"
    exports_sources = "include*", "src*", "CMakeLists.txt"

    def set_version(self):
        git = Git(self, self.recipe_folder)
        self.version = git.get_tag()
    
    def build_requirements(self):
        self.tool_requires("cmake/[>3.4, <4.0]")

    def requirements(self):
        self.requires("sdl2/2.26.5")
        self.requires("chipmunk2d/7.0.4")
        
        self.requires("tmx/1.10.0")
        self.requires("sdl2_image/2.6.3")

        self.requires("cjson/1.7.15")
        self.requires("sdl2_mixer/2.8.0")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def layout(self):
        cmake_layout(self)