#pragma once
//#include "Math.hpp"
//#include "Track.hpp"
//#include "Controller.hpp"
//#include <SFML/Graphics.hpp>

class Car
{
    Vec2 m_position;
    Vec2 m_heading;
    Vec2 m_velocity;
    Vec2 m_acceleration;
    float m_engineForce;
    float m_carAngle;
    float m_carWidth;
    float m_carHeight;
    const float carPower = 120000.0f;
    const float maxPower = 1000000.0f;
    const float turnSpeed = 300.0f;
    const float engineDecay = carPower*0.75;
    sf::RectangleShape m_carBody;
    sf::RectangleShape m_carHood;

    public:
    Car(Vec2 _position, Vec2 _heading, float _carWidth = 25.0f, float _carHeight = 15.0f)
    {
	m_position = _position;
	m_heading = _heading;
	m_velocity = Vec2(0.0f, 0.0f);
	m_acceleration = Vec2(0.0f, 0.0f);
	m_engineForce = 0.0f;
	m_carAngle = 0.0f;
	m_carWidth = _carWidth;
	m_carHeight = _carHeight;
	m_carBody.setSize(sf::Vector2f(_carWidth, _carHeight));
	m_carBody.setFillColor(sf::Color(20, 20, 60, 255));
	m_carHood.setSize(sf::Vector2f(_carWidth*2.0f, _carHeight));
	m_carHood.setFillColor(sf::Color(255, 255, 0, 255));

	
    }
    ~Car(){}; // no heap allocations so none needed
    
    Vec2 GetPosition()
    {
	return m_position;
    }
    Vec2 GetHeading()
    {
	return m_heading;
    }
    Vec2 GetVelocity()
    {
	return m_velocity;
    }
    Vec2 GetAcceleration()
    {
	return m_acceleration;
    }
    float GetEngineForce()
    {
	return m_engineForce;
    }
    
    void Update(float dt, Controller controller)
    {
	// handle input response
	if (controller.up) {
	    if (m_engineForce < maxPower) {
		m_engineForce += (carPower*dt);
	    }
	} else if (controller.down) {
	    if (m_engineForce > -maxPower) {
		m_engineForce -= (carPower*dt);
	    }
	} else {
	    // initially had the sign calculation as a lambda
	    // but realized there's actually no need/benefit
	    float sign =  m_engineForce > 0 ? 1 : -1;
	    float epsilon = 10;
	    if (fabsf(m_engineForce) < epsilon) {
		m_engineForce = 0.0f;
	    } else {
		m_engineForce -= (sign*engineDecay * dt);
	    }
	}
	if (controller.left) {
	    m_carAngle -= (turnSpeed * dt);
	}
	if (controller.right) {
	    m_carAngle += (turnSpeed * dt);
	}
	
	m_heading = Vec2(cos(degToRad(m_carAngle)), sin(degToRad(m_carAngle)));

	// perform a basic eulerian integration
	m_acceleration = (m_heading * m_engineForce);

	m_velocity += (m_acceleration * dt);

	Vec2 friction = m_velocity * -0.5f;

	m_velocity += friction;

	m_position += (m_velocity * dt);
	
    }
    void Render(sf::RenderWindow& window)
    {
	m_carBody.setRotation(m_carAngle);
	m_carBody.setPosition(m_position.x - m_carWidth / 2.0f, m_position.y + m_carHeight/2.0f);
	m_carHood.setRotation(m_carAngle);
	m_carHood.setPosition(m_position.x - m_carWidth / 2.0f, m_position.y + m_carHeight/2.0f);
	window.draw(m_carHood);
	window.draw(m_carBody);
    }
    
};
