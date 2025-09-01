from conan import ConanFile
from conan.tools.scm import Git

class MetroidVaniaConan(ConanFile):
    name="MetroidVania"
    exports_sources = "include*", "src*", "CMakeLists.txt"

    def set_version(self):
        git = Git(self, self.recipe_folder)
        self.version = git.get_tag()
    
    def build_requirements(self):
