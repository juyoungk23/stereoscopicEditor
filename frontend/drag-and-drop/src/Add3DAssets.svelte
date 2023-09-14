<script>
  const bucketLink =
    "https://storage.googleapis.com/stereoscopic-test-3d-assets/AssetBundles/myobject_bundle";
  const myAssetName = "abstract_object(75).fbx";
  const assetPosition = { x: 0, y: 0, z: 30 };

  async function load3DAsset() {
    const url = "http://35.215.89.200:8080/Load3DAsset";
    const data = {
      gcsLink: bucketLink,
      assetName: myAssetName,
      assetPosition: assetPosition,
    };

    console.log("Data sent to server: ", JSON.stringify(data));

    const response = await fetch(url, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(data),
    });
    // Handle response
  }
</script>

<button
  on:click={() => {
    console.log(
      "Uploading 3d asset from GCP",
      bucketLink,
      myAssetName,
      assetPosition
    );
    load3DAsset();
  }}>Add 3D Asset</button
>
