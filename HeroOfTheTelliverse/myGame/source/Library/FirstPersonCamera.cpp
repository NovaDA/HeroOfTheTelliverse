#include "FirstPersonCamera.h"
#include "Game.h"
#include "GameTime.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "VectorHelper.h"

namespace Library
{
    RTTI_DEFINITIONS(FirstPersonCamera)

    const float FirstPersonCamera::DefaultRotationRate = XMConvertToRadians(1.0f);
    const float FirstPersonCamera::DefaultMovementRate = 10.0f;
    const float FirstPersonCamera::DefaultMouseSensitivity = 100.0f;

    FirstPersonCamera::FirstPersonCamera(Game& game)
        : Camera(game), mKeyboard(nullptr), mMouse(nullptr), 
          mMouseSensitivity(DefaultMouseSensitivity), mRotationRate(DefaultRotationRate), mMovementRate(DefaultMovementRate)
    {
    }

    FirstPersonCamera::FirstPersonCamera(Game& game, float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
        : Camera(game, fieldOfView, aspectRatio, nearPlaneDistance, farPlaneDistance), mKeyboard(nullptr), mMouse(nullptr),
          mMouseSensitivity(DefaultMouseSensitivity), mRotationRate(DefaultRotationRate), mMovementRate(DefaultMovementRate)
          
    {
    }

    FirstPersonCamera::~FirstPersonCamera()
    {
        mKeyboard = nullptr;
        mMouse = nullptr;
    }

    const Keyboard& FirstPersonCamera::GetKeyboard() const
    {
        return *mKeyboard;
    }

    void FirstPersonCamera::SetKeyboard(Keyboard& keyboard)
    {
        mKeyboard = &keyboard;
    }

    const Mouse& FirstPersonCamera::GetMouse() const
    {
        return *mMouse;
    }

    void FirstPersonCamera::SetMouse(Mouse& mouse)
    {
        mMouse = &mouse;
    }

    float&FirstPersonCamera:: MouseSensitivity()
    {
        return mMouseSensitivity;
    }


    float& FirstPersonCamera::RotationRate()
    {
        return mRotationRate;
    }

    float& FirstPersonCamera::MovementRate()
    {
        return mMovementRate;
    }

    void FirstPersonCamera::Initialize()
    {
        mKeyboard = (Keyboard*)mGame->Services().GetService(Keyboard::TypeIdClass());
        mMouse = (Mouse*)mGame->Services().GetService(Mouse::TypeIdClass());

        Camera::Initialize();
    }


	void FirstPersonCamera::SetPositionCamera(XMFLOAT3 camPos)
	{
		XMFLOAT3 camPo = camPos;
		//cameraNewPos = camPo;

		CameraPosition = XMLoadFloat3(&camPo);
	}





    void FirstPersonCamera::Update(const GameTime& gameTime)
    {
		XMFLOAT3 movementAmount = Vector3Helper::Zero;
       
        XMFLOAT2 rotationAmount = Vector2Helper::Zero;
        if ((mMouse != nullptr) && (mMouse->IsButtonHeldDown(MouseButtonsLeft)))
        {
            LPDIMOUSESTATE mouseState = mMouse->CurrentState();			
            rotationAmount.x = -mouseState->lX * mMouseSensitivity;
            rotationAmount.y = -mouseState->lY * mMouseSensitivity;
        }

		//float elapsedTime = (float)gameTime.ElapsedGameTime();
		//XMVECTOR rotationVector = XMLoadFloat2(&rotationAmount) * mRotationRate;// *elapsedTime;
       XMVECTOR right = XMLoadFloat3(&mRight);

  //      XMMATRIX pitchMatrix = XMMatrixRotationAxis(right, XMVectorGetY(rotationVector));
  //      XMMATRIX yawMatrix = XMMatrixRotationY(XMVectorGetX(rotationVector));

  //      ApplyRotation(XMMatrixMultiply(pitchMatrix, yawMatrix));

        
        
        XMStoreFloat3(&mPosition, CameraPosition);

        Camera::Update(gameTime);
    }
}
