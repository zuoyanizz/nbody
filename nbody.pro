TEMPLATE = subdirs

SUBDIRS += nbody test

src.subdir = src
#src.depends = 

test.subdir = test
test.depends = nbody