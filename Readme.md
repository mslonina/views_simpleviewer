Views Simpleviewer
==================

Requirements
------------

Views, Views Data Export

Description
-----------

Exports data in a Simpleviewer Gallery file. Gallery can be included in the node by filter
[simpleviewer:path/to/gallery], which you can enable in Text Formats.

Example usage
--------------

Create a node or file view which takes as an argument node nid. Put fields: file name (and
make it link) and description field (or whatever you want as a description...). On the
style configuration choose which field is a file, which is description, choose which image
styles will be applied and other Simpleviewer configuration. Save it with path, i.e.
node/%/xml.

Now, edit some node, and put [simpleviewer:node/2/xml], where "2" is the nid of your node. 

You can use in that way any gallery file. Even outside Drupal root.

Todo list
---------

- Different thumbnails and preview
- Check if field for filename is image
- Input validation
- Parse views arguments as Flickr user etc.
- Choose Flickr user according to the field
- Choose Flickr Tags accroding to the specified field
