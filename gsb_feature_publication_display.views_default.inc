<?php
/**
 * @file
 * gsb_feature_publication_display.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gsb_feature_publication_display_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'gsb_publications_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'GSB Publications Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_authors' => 'field_authors',
    'field_pub_book_title' => 'field_pub_book_title',
    'field_place_of_publication' => 'field_place_of_publication',
    'field_publisher' => 'field_publisher',
    'field_pub_date_month' => 'field_pub_date_month',
    'field_pub_date_day' => 'field_pub_date_day',
    'field_year_of_publication' => 'field_year_of_publication',
    'field_volume_number' => 'field_volume_number',
    'field_issue_number' => 'field_issue_number',
    'field_page_count' => 'field_page_count',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Publication year (field_year_of_publication) */
  $handler->display->display_options['sorts']['field_year_of_publication_value']['id'] = 'field_year_of_publication_value';
  $handler->display->display_options['sorts']['field_year_of_publication_value']['table'] = 'field_data_field_year_of_publication';
  $handler->display->display_options['sorts']['field_year_of_publication_value']['field'] = 'field_year_of_publication_value';
  $handler->display->display_options['sorts']['field_year_of_publication_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'publications_listing_entity_view');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Journals and Other Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'show-more-less show-more-less-num-3 show-more-less-min-5';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Authors (field_authors) */
  $handler->display->display_options['relationships']['field_authors_value']['id'] = 'field_authors_value';
  $handler->display->display_options['relationships']['field_authors_value']['table'] = 'field_data_field_authors';
  $handler->display->display_options['relationships']['field_authors_value']['field'] = 'field_authors_value';
  $handler->display->display_options['relationships']['field_authors_value']['label'] = 'Authors';
  $handler->display->display_options['relationships']['field_authors_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_person_fac_single_ref_target_id']['id'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['relationships']['field_person_fac_single_ref_target_id']['table'] = 'field_data_field_person_fac_single_ref';
  $handler->display->display_options['relationships']['field_person_fac_single_ref_target_id']['field'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['relationships']['field_person_fac_single_ref_target_id']['relationship'] = 'field_authors_value';
  $handler->display->display_options['relationships']['field_person_fac_single_ref_target_id']['label'] = 'Author';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Authors */
  $handler->display->display_options['fields']['field_authors']['id'] = 'field_authors';
  $handler->display->display_options['fields']['field_authors']['table'] = 'field_data_field_authors';
  $handler->display->display_options['fields']['field_authors']['field'] = 'field_authors';
  $handler->display->display_options['fields']['field_authors']['label'] = '';
  $handler->display->display_options['fields']['field_authors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_authors']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_authors']['settings'] = array(
    'view_mode' => 'existing_node_teaser',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_authors']['delta_offset'] = '0';
  /* Field: Content: Source Publication / Book Title */
  $handler->display->display_options['fields']['field_pub_book_title']['id'] = 'field_pub_book_title';
  $handler->display->display_options['fields']['field_pub_book_title']['table'] = 'field_data_field_pub_book_title';
  $handler->display->display_options['fields']['field_pub_book_title']['field'] = 'field_pub_book_title';
  $handler->display->display_options['fields']['field_pub_book_title']['label'] = '';
  $handler->display->display_options['fields']['field_pub_book_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pub_book_title']['alter']['text'] = '<em>[field_pub_book_title].</em>';
  $handler->display->display_options['fields']['field_pub_book_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pub_book_title']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Place of publication */
  $handler->display->display_options['fields']['field_place_of_publication']['id'] = 'field_place_of_publication';
  $handler->display->display_options['fields']['field_place_of_publication']['table'] = 'field_data_field_place_of_publication';
  $handler->display->display_options['fields']['field_place_of_publication']['field'] = 'field_place_of_publication';
  $handler->display->display_options['fields']['field_place_of_publication']['label'] = '';
  $handler->display->display_options['fields']['field_place_of_publication']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_place_of_publication']['alter']['text'] = '[field_place_of_publication]:';
  $handler->display->display_options['fields']['field_place_of_publication']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_place_of_publication']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['label'] = '';
  $handler->display->display_options['fields']['field_publisher']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publisher']['alter']['text'] = '[field_publisher],';
  $handler->display->display_options['fields']['field_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Publication Month */
  $handler->display->display_options['fields']['field_pub_date_month']['id'] = 'field_pub_date_month';
  $handler->display->display_options['fields']['field_pub_date_month']['table'] = 'field_data_field_pub_date_month';
  $handler->display->display_options['fields']['field_pub_date_month']['field'] = 'field_pub_date_month';
  $handler->display->display_options['fields']['field_pub_date_month']['label'] = '';
  $handler->display->display_options['fields']['field_pub_date_month']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pub_date_month']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pub_date_month']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Publication Day */
  $handler->display->display_options['fields']['field_pub_date_day']['id'] = 'field_pub_date_day';
  $handler->display->display_options['fields']['field_pub_date_day']['table'] = 'field_data_field_pub_date_day';
  $handler->display->display_options['fields']['field_pub_date_day']['field'] = 'field_pub_date_day';
  $handler->display->display_options['fields']['field_pub_date_day']['label'] = '';
  $handler->display->display_options['fields']['field_pub_date_day']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pub_date_day']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pub_date_day']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Publication year */
  $handler->display->display_options['fields']['field_year_of_publication']['id'] = 'field_year_of_publication';
  $handler->display->display_options['fields']['field_year_of_publication']['table'] = 'field_data_field_year_of_publication';
  $handler->display->display_options['fields']['field_year_of_publication']['field'] = 'field_year_of_publication';
  $handler->display->display_options['fields']['field_year_of_publication']['label'] = '';
  $handler->display->display_options['fields']['field_year_of_publication']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_year_of_publication']['alter']['text'] = '[field_pub_date_month] [field_pub_date_day], [field_year_of_publication],';
  $handler->display->display_options['fields']['field_year_of_publication']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year_of_publication']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Volume Number */
  $handler->display->display_options['fields']['field_volume_number']['id'] = 'field_volume_number';
  $handler->display->display_options['fields']['field_volume_number']['table'] = 'field_data_field_volume_number';
  $handler->display->display_options['fields']['field_volume_number']['field'] = 'field_volume_number';
  $handler->display->display_options['fields']['field_volume_number']['label'] = '';
  $handler->display->display_options['fields']['field_volume_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_volume_number']['alter']['text'] = '[field_volume_number],';
  $handler->display->display_options['fields']['field_volume_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_volume_number']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Issue Number */
  $handler->display->display_options['fields']['field_issue_number']['id'] = 'field_issue_number';
  $handler->display->display_options['fields']['field_issue_number']['table'] = 'field_data_field_issue_number';
  $handler->display->display_options['fields']['field_issue_number']['field'] = 'field_issue_number';
  $handler->display->display_options['fields']['field_issue_number']['label'] = '';
  $handler->display->display_options['fields']['field_issue_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_issue_number']['alter']['text'] = '[field_issue_number],';
  $handler->display->display_options['fields']['field_issue_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_number']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_page_count']['id'] = 'field_page_count';
  $handler->display->display_options['fields']['field_page_count']['table'] = 'field_data_field_page_count';
  $handler->display->display_options['fields']['field_page_count']['field'] = 'field_page_count';
  $handler->display->display_options['fields']['field_page_count']['label'] = '';
  $handler->display->display_options['fields']['field_page_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_count']['alter']['text'] = '[field_page_count].';
  $handler->display->display_options['fields']['field_page_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_count']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'faculty',
  );
  $handler->display->display_options['show_title'] = 1;
  $export['gsb_publications_listing'] = $view;

  return $export;
}
