#include <iostream>
#include <fstream>
#include "vw.h"

int main(int argc, char** argv)
{
    auto vw = VW::initialize("-k -l 20 --initial_t 128000 --power_t 1 -c --passes 8 --invariant --ngram 3 --skips 1 --holdout_off");

    std::cerr << "Reading data from: " << argv[1] << std::endl;
    std::cerr << "Writing model to: " << argv[2] << std::endl;

    std::fstream data_file(argv[1]);
    std::string line;
    while (std::getline(data_file, line))
    {
        // assumes single-line examples; multi-line (e.g. for CB) is more complex
        example* ex = VW::read_example(*vw, line);

        vw->learn(*ex);

        VW::finish_example(*vw, *ex);

        // note that this is a manual driver. If you want to use vw in the same mode as the executable
        // use this code instead (and add appropriate -i, -f, -d, etc. lines)
        /*
        
        VW::start_parser(*vw);
        LEARNER::generic_driver(*vw);
        VW::end_parser(*vw);

        VW::sync_stats(*vw);
        
        */
    }

    VW::save_predictor(*vw, argv[2]);

    VW::finish(*vw);

    return 0;
}