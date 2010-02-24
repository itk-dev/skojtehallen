<?php

// $Id$

/**
 * @file Defines content type with CCK fields for the events.
 */

/**
 * The exported content type with CCK fields.
 *
 * @return array
 */
function _simple_event_cck_import() {
  $content['type']  = array (
    'name' => 'Aktiviteter',
    'type' => 'event',
    'description' => 'Aktiviteter har en start og en slutdato. Det er også muligt at aktivere tilmelding på aktiviteter.',
    'title_label' => 'Title',
    'body_label' => '',
    'min_word_count' => '0',
    'help' => '',
    'node_options' =>
    array (
      'status' => true,
      'revision' => true,
      'promote' => false,
      'sticky' => false,
    ),
    'language_content_type' => '0',
    'old_type' => 'event',
    'orig_type' => 'event',
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
    'node_repeat_type' => 0,
    'node_repeat_autodetachondatechange' => 0,
  );
  $content['fields']  = array (
    0 =>
    array (
      'label' => 'Forsidehenvisning',
      'field_name' => 'field_summary',
      'type' => 'text',
      'widget_type' => 'text_textarea',
      'change' => 'Change basic information',
      'weight' => '-4',
      'rows' => '5',
      'size' => 60,
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_summary][0][value',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' => NULL,
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'text_processing' => '1',
      'max_length' => '',
      'allowed_values' => '',
      'allowed_values_php' => '',
      'op' => 'Save field settings',
      'module' => 'text',
      'widget_module' => 'text',
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
        'format' =>
        array (
          'type' => 'int',
          'unsigned' => true,
          'not null' => false,
          'views' => false,
        ),
      ),
      'display_settings' =>
      array (
        'weight' => '-4',
        'parent' => '',
        'label' =>
        array (
          'format' => 'hidden',
        ),
        'teaser' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'full' =>
        array (
          'format' => 'hidden',
          'exclude' => 1,
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
      'label' => 'Beskrivelse',
      'field_name' => 'field_eventdescription',
      'type' => 'text',
      'widget_type' => 'text_textarea',
      'change' => 'Change basic information',
      'weight' => '-3',
      'rows' => '5',
      'size' => 60,
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_eventdescription][0][value',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' =>
      array (
        'field_eventdescription' =>
        array (
          0 =>
          array (
            'value' => '',
            '_error_element' => 'default_value_widget][field_eventdescription][0][value',
            'format' => 1,
          ),
        ),
      ),
      'group' => false,
      'required' => 0,
      'multiple' => '0',
      'text_processing' => '1',
      'max_length' => '',
      'allowed_values' => '',
      'allowed_values_php' => '',
      'op' => 'Save field settings',
      'module' => 'text',
      'widget_module' => 'text',
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
        'format' =>
        array (
          'type' => 'int',
          'unsigned' => true,
          'not null' => false,
          'views' => false,
        ),
      ),
      'display_settings' =>
      array (
        'weight' => '-3',
        'parent' => '',
        'label' =>
        array (
          'format' => 'hidden',
        ),
        'teaser' =>
        array (
          'format' => 'hidden',
          'exclude' => 1,
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
    2 =>
    array (
      'label' => 'Arrangementstidspunkt',
      'field_name' => 'field_arrangement_start',
      'type' => 'date',
      'widget_type' => 'date_popup_repeat',
      'change' => 'Change basic information',
      'weight' => '-2',
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'input_format' => 'M j Y - H:i:s',
      'input_format_custom' => '',
      'year_range' => '-3:+3',
      'increment' => '1',
      'advanced' =>
      array (
        'label_position' => 'above',
        'text_parts' =>
        array (
          'year' => 0,
          'month' => 0,
          'day' => 0,
          'hour' => 0,
          'minute' => 0,
          'second' => 0,
        ),
      ),
      'label_position' => 'above',
      'text_parts' =>
      array (
      ),
      'description' => '',
      'group' => false,
      'required' => 1,
      'multiple' => 1,
      'repeat' => 1,
      'todate' => 'optional',
      'granularity' =>
      array (
        'year' => 'year',
        'month' => 'month',
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
      ),
      'default_format' => 'medium',
      'tz_handling' => 'site',
      'timezone_db' => 'UTC',
      'repeat_collapsed' => '1',
      'op' => 'Save field settings',
      'module' => 'date',
      'widget_module' => 'date',
      'columns' =>
      array (
        'value' =>
        array (
          'type' => 'varchar',
          'length' => 20,
          'not null' => false,
          'sortable' => true,
          'views' => true,
        ),
        'value2' =>
        array (
          'type' => 'varchar',
          'length' => 20,
          'not null' => false,
          'sortable' => true,
          'views' => false,
        ),
        'rrule' =>
        array (
          'type' => 'text',
          'not null' => false,
          'sortable' => false,
          'views' => false,
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
  );
  $content['extra']  = array (
    'title' => '-5',
    'revision_information' => '1',
    'menu' => '-1',
    'path' => '0',
  );
  
  return $content;
}

/**
 * Installs the simeple event content type.
 *
 */
function _simple_event_cck_install() {
  // Get CCK content.
  $content = _simple_event_cck_import();

  // CCK content_copy.module may not be enabled, so make sure it is included.
  include_once './' . drupal_get_path('module', 'content') . '/modules/content_copy/content_copy.module';

  $form_state['values']['type_name'] = '<create>';
  $form_state['values']['macro'] = '$content = ' . var_export($content, TRUE) . ';';

  // form provided by content_copy.module
  drupal_execute('content_copy_import_form', $form_state);
  content_clear_type_cache();
}