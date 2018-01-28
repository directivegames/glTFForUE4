// Copyright 2017 - 2018 Code 4 Game, Org. All Rights Reserved.

#pragma once

#include "glTF/glTFImporter.h"

class FglTFImporterEd : public FglTFImporter
{
    typedef FglTFImporter Super;

public:
    static TSharedPtr<FglTFImporterEd> Get(UClass* InClass, UObject* InParent, FName InName, EObjectFlags InFlags, class FFeedbackContext* InFeedbackContext);

public:
    FglTFImporterEd();
    virtual ~FglTFImporterEd();

public:
    virtual UObject* Create(const TWeakPtr<struct FglTFImportOptions>& InglTFImportOptions, const std::shared_ptr<libgltf::SGlTF>& InGlTF) const override;

private:
    UStaticMesh* CreateStaticMesh(const TWeakPtr<struct FglTFImportOptions>& InglTFImportOptions, const std::shared_ptr<libgltf::SGlTF>& InGlTF, const std::shared_ptr<libgltf::SScene>& InScene, const class FglTFBufferFiles& InBufferFiles) const;
    bool GenerateRawMesh(const std::shared_ptr<libgltf::SGlTF>& InGlTF, const struct FTransform& InTransform, const std::shared_ptr<libgltf::SNode>& InNode, const class FglTFBufferFiles& InBufferFiles, struct FRawMesh& OutRawMesh, TArray<int32>& InOutMaterialIds, const glTFForUE4::FFeedbackTaskWrapper& InFeedbackTaskWrapper) const;
    bool GenerateRawMesh(const std::shared_ptr<libgltf::SGlTF>& InGlTF, const struct FTransform& InTransform, const std::shared_ptr<libgltf::SMesh>& InMesh, const class FglTFBufferFiles& InBufferFiles, struct FRawMesh& OutRawMesh, TArray<int32>& InOutMaterialIds, const glTFForUE4::FFeedbackTaskWrapper& InFeedbackTaskWrapper) const;
    bool GenerateRawMesh(const std::shared_ptr<libgltf::SGlTF>& InGlTF, const struct FTransform& InTransform, const std::shared_ptr<libgltf::SMeshPrimitive>& InMeshPrimitive, const class FglTFBufferFiles& InBufferFiles, struct FRawMesh& OutRawMesh, const glTFForUE4::FFeedbackTaskWrapper& InFeedbackTaskWrapper) const;

private:
    UStaticMesh* CreateStaticMesh(const TWeakPtr<struct FglTFImportOptions>& InglTFImportOptions, const std::shared_ptr<libgltf::SMesh>& InMesh, const std::shared_ptr<libgltf::SGlTF>& InGlTF, const class FglTFBufferFiles& InBufferFiles) const;
    bool CreateNode(const TWeakPtr<struct FglTFImportOptions>& InglTFImportOptions, const std::vector<std::shared_ptr<libgltf::SGlTFId>>& InNodeIndices, const std::shared_ptr<libgltf::SGlTF>& InGlTF, const class FglTFBufferFiles& InBufferFiles, FText InParentNodeName, TArray<UStaticMesh*>& OutStaticMeshes) const;
};
