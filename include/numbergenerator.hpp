//
// Created by fdiez on 8/27/21.
// Adapted from: https://www.scratchapixel.com/lessons/procedural-generation-virtual-worlds/procedural-patterns-noise-part-1/creating-simple-1D-noise
//

#ifndef SDL2TEST_NUMBERGENERATOR_HPP
#define SDL2TEST_NUMBERGENERATOR_HPP

#include <random>
#include <cstddef>

class NumberGenerator {
public:
    // 1D Perlin simplex noise
    static float noise(float x);

    static float randomFloat(float min, float max);

    static int randomInt(int min, int max);
};

#endif //SDL2TEST_NUMBERGENERATOR_HPP
