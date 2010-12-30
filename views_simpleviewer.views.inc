<?php
// $Id$

/**
 * @file
 * Views Simpleviewer plugin definition.
 */

/**
 * Implements hook_views_plugins().
 */
function views_simpleviewer_views_plugins() {
  return array(
    'style' => array(
      'views_simpleviewer' => array(
        'title' => t('Views Simpleviewer'),
        'theme' => 'views_view_simpleviewer',
        'help' => t('Render result for the Simpleviewer gallery.'),
        'handler' => 'views_simpleviewer_style_plugin',
        'export headers' => array('Content-Type' => 'text/xml'),
        'export feed type' => 'simpleviewer',
        'export feed text' => 'Simpleviewer XML',
        'export feed file' => 'gallery.xml',
        'parent' => 'views_simpleviewer',
        'uses row plugin' => FALSE,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' =>  'data_export',
      ),
    ),
  );
}

