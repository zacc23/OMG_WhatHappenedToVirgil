OhMyGodWhatHappenedToVirgil
==============================

### Testing

`c++ tests/test2.cpp -I. -o test2 && ./test2`

### Plotting

Install CERN Root (https://root.cern/)

`c++ examples/plot.cpp -I. $(root-config --cflags --libs) -o plot && ./plot`
(creates PNG and PDF file for viewing)

------------------------------

* Submit pull requests with a notice on why your changes or additions are necessary

### Copyright

Copyright (c) 2022, zacc23

This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
