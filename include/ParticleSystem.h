#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class ParticleSystem {
public:
    ParticleSystem(unsigned int count);

    void update(float dt);
    void render(sf::RenderWindow& window);

private:
    struct Particle {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index);

    std::vector<Particle> particles;
    std::vector<sf::Vertex> vertices;
    sf::Time lifetime;
    sf::Vector2f emitter;
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution;
};

#endif // PARTICLE_SYSTEM_H