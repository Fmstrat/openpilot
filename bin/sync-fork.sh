#!/usr/bin/env bash

UPSTREAM="https://github.com/j-vanetten/openpilot.git"

set -e
if [ -z "$(git remote -v |grep upstream)" ]; then
    set -x
    git checkout --track origin/jvePilot-beta
    git checkout jvePilot-release
    git remote add upstream ${UPSTREAM}
    { set +x; } 2>/dev/null
fi
set -x
git fetch upstream
git checkout jvePilot-release
git pull
git merge upstream/jvePilot-release
git push
git checkout jvePilot-beta
git pull
git merge upstream/jvePilot-beta
git push
git checkout jvePilot-release
{ set +x; } 2>/dev/null