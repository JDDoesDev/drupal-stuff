<?php


/**
 * The Salesperson Alert Module Admin Menu Form
 */
function spam_admin_settings_form() {
  $form = array();
  $message = variable_get('spam_message', 'Enter the body of the message here');
  if (is_array($message)) {
    $message = $message['value'];
  }
  $form['spam_description'] = array(
    '#markup' => '<p>Enter the information you would like sent out here.  You can use a few tokens if you want.</p><ul><li>[sales:company] = The company being referenced</li><li>[sales:url] = The URL of the article being referenced</li></ul>'
  );

  $form['spam_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Sender\'s Email'),
    '#default_value' => variable_get('spam_from'),
    '#required' => TRUE,
  );

  $form['spam_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Subject'),
    '#default_value' => variable_get('spam_subject'),
    '#required' => TRUE,
  );

  $form['spam_message'] = array(
    '#type' => 'text_format',
    '#title' => t('Your Message'),
    '#default_value' => $message,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
   );

   return $form;
}

function spam_admin_settings_form_submit($form, $form_state) {
  variable_set('spam_from', $form_state['values']['spam_from']);
  variable_set('spam_message', $form_state['values']['spam_message']);
  variable_set('spam_subject', $form_state['values']['spam_subject']);

  drupal_set_message(t('Settings successfully saved'));
}
