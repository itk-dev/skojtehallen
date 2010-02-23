<?php

/**
 * @file Defines an CCK imagefield to extend the banner content type.
 */

/**
 * CCK imagefield export. Should be used to get CCK imagefield add to the banner content type.
 *
 * @return array
 */
function _fading_banner_cck_export() {
  $content['type']  = array (
    'name' => 'Fading banner',
    'type' => 'fading_banner',
    'description' => 'Banners display by using flash to fade them (Mostly used as header banners)',
    'title_label' => 'Title',
    'body_label' => '',
    'min_word_count' => '0',
    'help' => '',
    'node_options' =>
    array (
      'status' => false,
      'promote' => false,
      'sticky' => false,
      'revision' => false,
    ),
    'language_content_type' => '0',
    'old_type' => 'fading_banner',
    'orig_type' => '',
    'module' => 'node',
    'custom' => '1',
    'modified' => '1',
    'locked' => '0',
    'menu' =>
    array (
      'admin' => false,
      'devel' => false,
      'navigation' => false,
      'secondary-links' => false,
      'menu-isbanen-links' => false,
      'primary-links' => false,
    ),
    'event_nodeapi' => 'never',
  );
  $content['fields']  = array (
    0 =>
    array (
      'label' => 'Association',
      'field_name' => 'field_association',
      'type' => 'text',
      'widget_type' => 'optionwidgets_buttons',
      'change' => 'Change basic information',
      'weight' => '-4',
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'value' => 'Skøjtehallen',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' => NULL,
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'text_processing' => '0',
      'max_length' => '',
      'allowed_values' => 'Skøjtehallen
    Isbanen',
      'allowed_values_php' => '',
      'op' => 'Save field settings',
      'module' => 'text',
      'widget_module' => 'optionwidgets',
      'columns' =>
      array (
        'value' =>
        array (
          'type' => 'text',
          'size' => 'big',
          'not null' => false,
          'sortable' => true,
          'views' => true,
        ),
      ),
      'display_settings' =>
      array (
        'label' =>
        array (
          'format' => 'above',
          'exclude' => 0,
        ),
        'teaser' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'full' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        4 =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        2 =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        3 =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'token' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
      ),
    ),
    1 =>
    array (
      'label' => ' Banner',
      'field_name' => 'field_fading_banner',
      'type' => 'filefield',
      'widget_type' => 'imagefield_widget',
      'change' => 'Change basic information',
      'weight' => '-3',
      'file_extensions' => 'jpg jpeg',
      'progress_indicator' => 'bar',
      'file_path' => 'fading_banners',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'custom_alt' => 0,
      'alt' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'title' => '',
      'use_default_image' => 0,
      'default_image_upload' => '',
      'default_image' => NULL,
      'description' => '',
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'list_field' => '0',
      'list_default' => 1,
      'description_field' => '0',
      'op' => 'Save field settings',
      'module' => 'filefield',
      'widget_module' => 'imagefield',
      'columns' =>
      array (
        'fid' =>
        array (
          'type' => 'int',
          'not null' => false,
          'views' => true,
        ),
        'list' =>
        array (
          'type' => 'int',
          'size' => 'tiny',
          'not null' => false,
          'views' => true,
        ),
        'data' =>
        array (
          'type' => 'text',
          'serialize' => true,
          'views' => true,
        ),
      ),
      'display_settings' =>
      array (
        'label' =>
        array (
          'format' => 'above',
          'exclude' => 0,
        ),
        'teaser' =>
        array (
          'format' => 'image_plain',
          'exclude' => 0,
        ),
        'full' =>
        array (
          'format' => 'image_plain',
          'exclude' => 0,
        ),
        4 =>
        array (
          'format' => 'image_plain',
          'exclude' => 0,
        ),
        2 =>
        array (
          'format' => 'image_plain',
          'exclude' => 0,
        ),
        3 =>
        array (
          'format' => 'image_plain',
          'exclude' => 0,
        ),
        'token' =>
        array (
          'format' => 'image_plain',
          'exclude' => 0,
        ),
      ),
    ),
  );
  $content['extra']  = array (
    'title' => '-5',
    'revision_information' => '-1',
    'menu' => '-2',
    'path' => '0',
  );
  
  return $content;
}

function _fading_banner_cck_install() {
  // Get CCK content.
  $content = _fading_banner_cck_export();

  // CCK content_copy.module may not be enabled, so make sure it is included.
  include_once './' . drupal_get_path('module', 'content') . '/modules/content_copy/content_copy.module';

  $form_state['values']['type_name'] = '<create>';
  $form_state['values']['macro'] = '$content = ' . var_export($content, TRUE) . ';';

  // form provided by content_copy.module
  drupal_execute('content_copy_import_form', $form_state);
  content_clear_type_cache();
}

?>
