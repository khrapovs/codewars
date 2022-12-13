#!/bin/bash

rm -rf igloo
git clone git@github.com:joakimkarlsson/igloo.git
pushd igloo || exit
git submodule update --init --recursive
popd || exit
