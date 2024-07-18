#
# Usage:
#   nix-shell --run "runAll"
#

let
  pkgs = import ./nixpkgs {};
in pkgs.mkShell {
  pname = "thinkcell-homework";
  version = "0.1";

  buildInputs = with pkgs; [
    gcc13
    cmake
    ninja
    gtest
  ];

  shellHook = ''
    build() {
      rm -rf cmake-build && mkdir cmake-build && cd cmake-build
      cmake -GNinja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
      ninja
    }

    run() {
      build
      ./homework
      cd ..
    }

    test() {
      build
      ./homework-tests
      cd ..
    }

    help() {
      echo ""
      echo "Welcome to the think cell solution made by Robert Richter 🚀 !"
      echo ""
      echo "Following commands are available:"
      echo "    - run: Build and run the solution."
      echo "    - test: Run the tests."
      echo "    - build: Build the solution."
      echo "    - help: Show this help message."
    }

    help
  '';
}

