//
//  main.cpp
//  CourseraCpp
//
//  Created by Valeriy Chevtaev on 10/17/13.
//  Copyright (c) 2013 7bit. All rights reserved.
//

#include <iostream>
#include "week04/game.h"

using namespace week04;

int main(int argc, const char * argv[])
{
    std::cout << "Coursera solutions." << std::endl;

    game app;
    app.run(argc, argv);

    std::cout << "Done." << std::endl;
    return 0;
}
