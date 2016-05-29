{
  "targets": [
    {
      "target_name": "voxelquest",
      "sources": ["voxelquest_node.cc"]
    }
  ],
  "include_dirs" : [
    "<!(node -e \"require('nan')\")"
  ]
}