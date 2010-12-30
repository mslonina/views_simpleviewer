<?php
// $Id$

/**
 * @file
 * Extends views_plugin_style class.
 */

class views_simpleviewer_style_plugin extends views_plugin_style {

  function option_definition() {
    //$options = parent::option_definition();
    $options['galleryStyle'] = array('default' => 'MODERN');
    $options['textColor'] = array('default' => '#FFFFFF');
    $options['frameColor'] = array('default' => '#FFFFFF');
    $options['frameWidth'] = array('default' => '20');
    $options['thumbPosition'] = array('default' => 'LEFT');
    $options['thumbColumns'] = array('default' => '3');
    $options['thumbRows'] = array('default' => '4');
    $options['showOpenButton'] = array('default' => 1);
    $options['showFullscreenButton'] = array('default' => 1);
    $options['thumbStyle'] = array('default' => 'views_simpleviewer_thumbnail');
    $options['previewStyle'] = array('default' => 'views_simpleviewer_preview');
    $options['captionField'] = array('default' => '');
    $options['imageField'] = array('default' => '');
    $options['useFlickr'] = array('default' => 0);
    $options['flickrUserName'] = array('default' => '');
    $options['flickrUserNameCustom'] = array('default' => '');
    $options['flickrTags'] = array('default' => '');
    $options['flickrTagsCustom'] = array('default' => '');
    $options['maxImageWidth'] = array('default' => 1100);
    $options['maxImageHeight'] = array('default' => 900);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    //parent::options_form($form, $form_state);

    // Return image styles
    $image_styles = image_styles();
    foreach ($image_styles as $key => $value) {
      $styles[$value['name']] = $value['name'];
    }

    // Return valid image fields
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      $images[] = $field;
    }

    // Return valid caption fields
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      $captions[] = $field;
    }
    // Return valid user fields
    $flickr_users[] = 'Custom';
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      $flickr_users[] = $field;
    }
    $flickr_tags[] = 'Custom';
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      $flickr_tags[] = $field;
    }

    $form['useFlickr'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Flickr'),
      '#default_value' => $this->options['useFlickr'],
    );
    $form['flickrUserName'] = array(
      '#type' => 'select',
      '#title' => t('Flickr User Name Field'),
      '#default_value' => $this->options['flickrUserName'],
      '#options' => $flickr_users,
    );
    $form['flickrUserNameCustom'] = array(
      '#type' => 'textfield',
      '#title' => t('Flickr User Name Custom'),
      '#default_value' => $this->options['flickrUserNameCustom'],
    );
    $form['flickrTags'] = array(
      '#type' => 'select',
      '#title' => t('Flickr Tags Field'),
      '#default_value' => $this->options['flickrTags'],
      '#options' => $flickr_tags,
    );
    $form['flickrTagsCustom'] = array(
      '#type' => 'textfield',
      '#title' => t('Flickr Tags Custom'),
      '#default_value' => $this->options['flickrTags'],
    );

    $form['imageField'] = array(
      '#type' => 'select',
      '#title' => t('Image Field'),
      '#default_value' => $this->options['imageField'],
      '#options' => $images,
    );
    
    $form['captionField'] = array(
      '#type' => 'select',
      '#title' => t('Caption Field'),
      '#default_value' => $this->options['captionField'],
      '#options' => $captions,
    );

    $form['galleryStyle'] = array(
      '#type' => 'select',
      '#title' => t('Gallery style'),
      '#default_value' => $this->options['galleryStyle'],
      '#options' => array(
        'MODERN' => t('Modern'),
        'COMPACT' => t('Compact'),
        'CLASSIC' => t('Classic'),
      ),
    );

    $form['thumbStyle'] = array(
      '#type' => 'select',
      '#title' => t('Thumbnail Style'),
      '#default_value' => $this->options['thumbStyle'],
      '#options' => $styles, 
    );
    $form['previewStyle'] = array(
      '#type' => 'select',
      '#title' => t('Preview Style'),
      '#default_value' => $this->options['previewStyle'],
      '#options' => $styles, 
    );
    $form['textColor'] = array(
      '#type' => 'textfield',
      '#title' => t('Color of the text'),
      '#default_value' => $this->options['textColor'],
    );
    $form['frameColor'] = array(
      '#type' => 'textfield',
      '#title' => t('Color of the frame'),
      '#default_value' => $this->options['frameColor'],
    );
    $form['frameWidth'] = array(
      '#type' => 'textfield',
      '#title' => t('Width of the frame'),
      '#default_value' => $this->options['frameWidth'],
    );
    $form['thumbPosition'] = array(
      '#type' => 'select',
      '#title' => t('Position of thumbnails'),
      '#default_value' => $this->options['thumbPosition'],
      '#options' => array(
        'TOP' => t('Top'),
        'BOTTOM' => t('Bottom'),
        'LEFT' => t('Left'),
        'RIGHT' => t('Right'),
        'NONE' => t('None'),
      ),
    );
    $form['thumbColumns'] = array(
      '#type' => 'textfield',
      '#title' => t('Columns of thumbnails'),
      '#default_value' => $this->options['thumbColumns'],
    );
    $form['thumbRows'] = array(
      '#type' => 'textfield',
      '#title' => t('Rows of thumbnails'),
      '#default_value' => $this->options['thumbRows'],
    );
    $form['showFullscreenButton'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show fullscreen button'),
      '#default_value' => $this->options['showFullscreenButton'],
      '#description' => t('If checked, fullscreen button will be showed'),
    );
    $form['showOpenButton'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show in new window button'),
      '#default_value' => $this->options['showOpenButton'],
      '#description' => t('If checked, show in new window button will be showed'),
    );

  }

}

