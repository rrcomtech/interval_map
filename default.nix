#
# Usage:
#   nix-shell --run test
#

let
  pkgs = import ./nixpkgs {};
in pkgs.mkShell {
  pname = "interval-map";
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

    test() {
      build
      ./tests
      cd ..
    }

    help() {
      echo ""
      echo "Welcome to the interval map implementation by Robert Richter🚀 !"
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

