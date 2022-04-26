OhMyGodWhatHappenedToVirgil
==============================

### Testing

`c++ tests/test2.cpp -I. -o test2 && ./test2`

### Plotting

Install CERN Root (https://root.cern/)

`c++ examples/plot.cpp -I. $(root-config --cflags --libs) -o plot && ./plot`
(creates PNG and PDF file for viewing)

### Copyright

Copyright (c) 2022, zacc23

CC0 1.0 Universal
