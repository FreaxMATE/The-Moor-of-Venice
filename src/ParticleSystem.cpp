#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned int count)
: particles(count), vertices(count * 4), lifetime(sf::seconds(5)), distribution(0, 1) {
    emitter = sf::Vector2f(400, 400); // Center of the window
}

void ParticleSystem::update(float dt) {
    for (std::size_t i = 0; i < particles.size(); ++i) {
        Particle& p = particles[i];
        p.lifetime -= sf::seconds(dt);
        if (p.lifetime <= sf::Time::Zero) {
            resetParticle(i);
        }
        for (int j = 0; j < 4; ++j) {
            vertices[i * 4 + j].position += p.velocity * dt;
        }
        float ratio = p.lifetime.asSeconds() / lifetime.asSeconds();
        for (int j = 0; j < 4; ++j) {
            vertices[i * 4 + j].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }
}

void ParticleSystem::render(sf::RenderWindow& window) {
    window.draw(&vertices[0], vertices.size(), sf::Quads);
}

void ParticleSystem::resetParticle(std::size_t index) {
    float angle = distribution(generator) * 360 * 3.14f / 180;
    float speed = distribution(generator) * 5 + 5; // Much slower speed
    particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    particles[index].lifetime = sf::milliseconds((distribution(generator) * 4000) + 2000); // Longer lifetime

    // Set the initial position of the particle
    sf::Vector2f position = sf::Vector2f(distribution(generator) * 800, distribution(generator) * 800); // Spread across the window

    // Set the size of the particle
    float size = 5.0f; // Smaller size

    // Define the four corners of the quad
    vertices[index * 4].position = position;
    vertices[index * 4 + 1].position = sf::Vector2f(position.x + size, position.y);
    vertices[index * 4 + 2].position = sf::Vector2f(position.x + size, position.y + size);
    vertices[index * 4 + 3].position = sf::Vector2f(position.x, position.y + size);

    // Set the color of the particle
    for (int j = 0; j < 4; ++j) {
        vertices[index * 4 + j].color = sf::Color::White;
    }
}