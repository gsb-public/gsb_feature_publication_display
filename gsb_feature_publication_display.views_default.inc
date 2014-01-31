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
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
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
  $handler->display->display_options['fields']['field_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['settings'] = array(
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
  $handler->display->display_options['fields']['field_place_of_publication']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_place_of_publication']['settings'] = array(
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
  $handler->display->display_options['fields']['field_year_of_publication']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year_of_publication']['settings'] = array(
    'format_type' => 'long',
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

  $view = new view();
  $view->name = 'publication_filters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Publication Filters';
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
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser_listing';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Authors (field_authors) */
  $handler->display->display_options['relationships']['field_authors_value']['id'] = 'field_authors_value';
  $handler->display->display_options['relationships']['field_authors_value']['table'] = 'field_data_field_authors';
  $handler->display->display_options['relationships']['field_authors_value']['field'] = 'field_authors_value';
  $handler->display->display_options['relationships']['field_authors_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 2;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 2;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Publication Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field collection item: Author (field_person_fac_single_ref) */
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['id'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['table'] = 'field_data_field_person_fac_single_ref';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['field'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['relationship'] = 'field_authors_value';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['group'] = 2;
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['expose']['operator_id'] = 'field_person_fac_single_ref_target_id_op';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['expose']['label'] = 'Author (field_person_fac_single_ref)';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['expose']['operator'] = 'field_person_fac_single_ref_target_id_op';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['expose']['identifier'] = 'field_person_fac_single_ref_target_id';
  $handler->display->display_options['filters']['field_person_fac_single_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'field_authors_value';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 2;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name (field_first_name)';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'field_authors_value';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 2;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name (field_last_name)';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Academic Area (field_academic_area_unlimited) */
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['id'] = 'field_academic_area_unlimited_tid';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['table'] = 'field_data_field_academic_area_unlimited';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['field'] = 'field_academic_area_unlimited_tid';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['expose']['operator_id'] = 'field_academic_area_unlimited_tid_op';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['expose']['label'] = 'Academic Area (field_academic_area_unlimited)';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['expose']['operator'] = 'field_academic_area_unlimited_tid_op';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['expose']['identifier'] = 'field_academic_area_unlimited_tid';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['vocabulary'] = 'academic_area';
  $handler->display->display_options['filters']['field_academic_area_unlimited_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Business Insight Topic (field_business_insight_topic) */
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['id'] = 'field_business_insight_topic_tid';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['table'] = 'field_data_field_business_insight_topic';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['field'] = 'field_business_insight_topic_tid';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['expose']['operator_id'] = 'field_business_insight_topic_tid_op';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['expose']['label'] = 'Business Insight Topic (field_business_insight_topic)';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['expose']['operator'] = 'field_business_insight_topic_tid_op';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['expose']['identifier'] = 'field_business_insight_topic_tid';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['vocabulary'] = 'business_insight_topic';
  $handler->display->display_options['filters']['field_business_insight_topic_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Region (field_region) */
  $handler->display->display_options['filters']['field_region_tid']['id'] = 'field_region_tid';
  $handler->display->display_options['filters']['field_region_tid']['table'] = 'field_data_field_region';
  $handler->display->display_options['filters']['field_region_tid']['field'] = 'field_region_tid';
  $handler->display->display_options['filters']['field_region_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_region_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_region_tid']['expose']['operator_id'] = 'field_region_tid_op';
  $handler->display->display_options['filters']['field_region_tid']['expose']['label'] = 'Region (field_region)';
  $handler->display->display_options['filters']['field_region_tid']['expose']['operator'] = 'field_region_tid_op';
  $handler->display->display_options['filters']['field_region_tid']['expose']['identifier'] = 'field_region_tid';
  $handler->display->display_options['filters']['field_region_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_region_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['field_region_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_region_tid']['vocabulary'] = 'region';
  $handler->display->display_options['filters']['field_region_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Centers (field_centers_research_programs) */
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['id'] = 'field_centers_research_programs_tid';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['table'] = 'field_data_field_centers_research_programs';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['field'] = 'field_centers_research_programs_tid';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['expose']['operator_id'] = 'field_centers_research_programs_tid_op';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['expose']['label'] = 'Centers (field_centers_research_programs)';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['expose']['operator'] = 'field_centers_research_programs_tid_op';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['expose']['identifier'] = 'field_centers_research_programs_tid';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    61 => 0,
    56 => 0,
    71 => 0,
    66 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    91 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    136 => 0,
    141 => 0,
    146 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
  );
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['vocabulary'] = 'centers_research_programs';
  $handler->display->display_options['filters']['field_centers_research_programs_tid']['hierarchy'] = 1;

  /* Display: Publication Filters */
  $handler = $view->new_display('panel_pane', 'Publication Filters', 'panel_pane_1');
  $handler->display->display_options['pane_title'] = 'Publications';
  $handler->display->display_options['pane_category']['name'] = 'Content Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'nid' => '',
    'title' => '',
    'field_authors_value' => '',
    'field_academic_area_unlimited_tid' => '',
    'field_business_insight_topic_tid' => '',
  );
  $export['publication_filters'] = $view;

  return $export;
}
