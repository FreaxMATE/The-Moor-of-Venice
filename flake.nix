{
  description = "mkdocs";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-24.11";
  };

  outputs = { self, nixpkgs, ... }:
  let
    system = "x86_64-linux";
  in {
    devShells."${system}".default =
    let
      pkgs = import nixpkgs {
        inherit system;
      };
    in pkgs.mkShell {
      packages = with pkgs; [
        gcc
        gdb
        cmake
        sfml
        meson
        pkg-config
        ninja
      ];

    };
  };
}