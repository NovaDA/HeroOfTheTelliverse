#pragma once

#include "DrawableGameComponent.h"
#include <DirectXCollision.h>

using namespace Library;

namespace Library
{
	class Mesh;
	class Keyboard;
}

namespace Rendering
{
	class ModelFromFile : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(ModelFromFile, DrawableGameComponent)

	public:
		ModelFromFile(Game& game, Camera& camera, const std::string modelFilename);
		ModelFromFile(Game& game, Camera& camera, const std::string modelFilename, const std::wstring modelDes, int modelValue);
		~ModelFromFile();

		virtual void Update(const GameTime& gameTime) override;
		const Keyboard& GetKeyboard() const;
		void SetKeyboard(Keyboard& keyboard);
		//texture switching functions
		void setTexture(std::wstring texturePath); //set the texture to the passed texture
		void clearTexture(); //reset the texture to the missing texture image

		virtual void SetPosition(const float rotateX, const float rotateY, const float rotateZ, const float scaleFactor, const float translateX, const float translateY, const float translateZ);
		virtual void SetPosition(const float rotateX, const float rotateY, const float rotateZ, const float translateX, const float translateY, const float translateZ);
		void setScale(float scaleX, float scaleY, float scaleZ);
		//bounding box require to access the world matrix

		XMFLOAT4X4* WorldMatrix() { return &mWorldMatrix; }

		//need to access this , make this public for simplicity
		DirectX::BoundingBox mBoundingBox;
		const std::wstring GetModelDes() { return modelDes; }
		int const ModelValue() { return mModelValue; }

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;
		Keyboard* mKeyboard;
		XMFLOAT3 getPosition(); //returns the positoon of the object
	private:
		typedef struct _TextureMappingVertex
		{
			XMFLOAT4 Position;
			XMFLOAT2 TextureCoordinates;

			_TextureMappingVertex() { }

			_TextureMappingVertex(XMFLOAT4 position, XMFLOAT2 textureCoordinates)
				: Position(position), TextureCoordinates(textureCoordinates) { }
		} TextureMappingVertex;

		ModelFromFile();
		ModelFromFile(const ModelFromFile& rhs);
		ModelFromFile& operator=(const ModelFromFile& rhs);

		void CreateVertexBuffer(ID3D11Device* device, const Mesh& mesh, ID3D11Buffer** vertexBuffer) const;

		ID3DX11Effect* mEffect;
		ID3DX11EffectTechnique* mTechnique;
		ID3DX11EffectPass* mPass;
		ID3DX11EffectMatrixVariable* mWvpVariable;

		ID3D11ShaderResourceView* mTextureShaderResourceView;
		ID3DX11EffectShaderResourceVariable* mColorTextureVariable;

		ID3D11InputLayout* mInputLayout;
		ID3D11Buffer* mVertexBuffer;
		ID3D11Buffer* mIndexBuffer;
		UINT mIndexCount;

		XMFLOAT4X4 mWorldMatrix;
		float mAngle;

		const std::string modelFile;

		float scaleX = 0.05f, scaleY = 0.05f, scaleZ = 0.05f; //initial scales
		std::wstring mTexturePath = L"Content\\Textures\\missing.jpg";

		

		XMFLOAT3 positionOfModel;
		float mMovementRate;
		std::wstring modelDes;
		int mModelValue;

	};
}