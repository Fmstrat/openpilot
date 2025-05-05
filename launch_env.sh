#!/usr/bin/env bash

#export FINGERPRINT="CHRYSLER PACIFICA 2018"
export FORCEWIFI=1
export FAKEUPLOAD=1
export OMP_NUM_THREADS=1
export MKL_NUM_THREADS=1
export NUMEXPR_NUM_THREADS=1
export OPENBLAS_NUM_THREADS=1
export VECLIB_MAXIMUM_THREADS=1

if [ -z "$AGNOS_VERSION" ]; then
  export AGNOS_VERSION="11.13"
fi

export STAGING_ROOT="/data/safe_staging"
