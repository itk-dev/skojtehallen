<?php

/**
 * Overide variables and create additional template suggestions based on aliased path
 */
function skojtehallen_preprocess_node(&$vars) {
  if ($vars['node']->type == "event") {
    $vars['template_files'][] = 'node-arrangementer';
  }
  if ($vars['node']->type == "news") {
    $vars['template_files'][] = 'node-nyheder';
  }
}

/**
 * Overide variables and create additional template suggestions based on aliased path
 */
function skojtehallen_preprocess_page(&$vars) {

  // Change site-switcher menu based on context
  $parts = split(' ', $vars['body_classes']);
  if (in_array('isbanen', $parts)) {
    $vars['subsite_menu'] = '<a class="subsite-menu" href="/" >Til Sk&oslash;jtehallen</a>';
  }
  else {
    $vars['subsite_menu'] = '<a class="subsite-menu" href="/isbanen/">Til Isbanen</a>';
  }

  if (strlen($vars['header'])) {
    $vars['header_link'] = '/';
  }
  else {
    $vars['header_link'] = '/isbanen';
  }

  /**
   * Generate additional template suggestions based on aliased path
   */

  if (module_exists('path')) {

    $path_alias = drupal_get_path_alias($_GET['q']);
    $alias_parts = explode('/', $path_alias);

    // Check for edit page
    $last = array_reverse($alias_parts);
    $last_part = $last[0];
    if ($last_part == 'data.xml') {
      $vars['template_files'] = array('page-xml');
      return;
    }

    if ($last_part != "edit") {

      // Generate array of templates
      $templates = array();
      $template_name = "page";

      foreach ($alias_parts as $part) {
        $template_name = $template_name. '-' .$part;
        $templates[] = $template_name;
      }

      // Add suggestions to template array
      $vars['template_files'] = $templates;

      // Get node being proccessd
      $node = $vars['node'];

      // Add date to News
      if ($node->type == 'news') {
        $vars['news_date'] = format_date($node->created, 'custom', 'F Y');
      }
      
      // Add date to event
      if ($node->type == 'event') {
        $no_of_dates = count($node->field_arrangement_start);
        if ($no_of_dates == 1) {
          // Not a repeating event
          $vars['event_date'] = format_date(strtotime($node->field_arrangement_start[0]['value']), 'custom', 'F Y');
        }
        else {
          // Repeating event
          $vars['event_date'] = format_date(strtotime($node->field_arrangement_start[0]['value']), 'custom', 'F Y') .' - '. format_date(strtotime($node->field_arrangement_start[$no_of_dates - 1]['value']), 'custom', 'F Y');
        }

        global $user;
        if ( !$user->uid ) {
          $vars['tabs'] = null; // Remove repaet events tab-menu, when not logged in
        }
      }
    } // End check for edit page
    else if ($last_part == 'data.xml') {
      $vars['template_files'] = 'page-xml';
    }
  } // End check for path module
	
  // Generate random style for changing images
  $vars['random_image_class'] = 'theme-style-' . rand(1, 4);

  // Append conditional styles
  $vars['styles'] .= $vars['conditional_styles'] = variable_get('conditional_styles_' . $GLOBALS['theme'], '');

} // End preprocess page function

/**
* Implementation of hook_theme.
*
* Register custom theme functions.
*/

function skojtehallen_theme() {
  return array(
    // The form ID.
    'contact_mail_page1' => array(
      // Forms always take the form argument.
      'arguments' => array('form' => NULL),
    ),
  );
}

/**
 * Theme override for user edit form.
 *
 * The function is named themename_formid.
 */

function skojtehallen_contact_mail_page1($form){
	// Change submit button
	$form['submit']['#type'] 	= "image_button" ;
	$form['submit']['#src'] 	= drupal_get_path('theme','skojtehallen')."/images/button-contact-form-submit.png";
	$form['submit']['#attributes']['class'] 	= "";
	
	// Set 'subject' and hide field
	$form['subject']['#type'] = "hidden";
	$form['subject']['#value'] = "Besked fra skojtehallen.dk";
	
	// unset 'Send yourself a copy'
	unset($form['copy']);
	// $form['copy']['#type'] = "hidden";
	
	return drupal_render($form);
}