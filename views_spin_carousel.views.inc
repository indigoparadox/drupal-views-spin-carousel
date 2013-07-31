<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

function template_preprocess_views_spin_carousel( &$vars ) {

   //dpm( $vars );

   /*
   $gallery_js = <<<EOF
jQuery(document).ready( function() {
   // TODO: Add view ID to selectors.
   jQuery('.view-id-{$vars['view']->name} div.iygallery-slides').cycle( { 
      'fx': '{$vars['options']['slide_transition']}', 
      'timeout': {$vars['options']['slide_timeout']}
   } );
   jQuery('.view-id-{$vars['view']->name} div.iygallery-thumbs').cycle( { 
      'fx': 'scrollHorz',
      'next': 'a.iygallery-thumbs-next',
      'prev': 'a.iygallery-thumbs-previous',
      'timeout': 0
   } );
} );

EOF;

   drupal_add_css(
      drupal_get_path( 'module', 'irrigableyam' ).'/views-view-iygallery.css'
   );
   drupal_add_js( 
      libjunk_get_libraries_path( 'jquery.cycle' ).
         '/jquery.cycle/jquery.cycle.all.min.js',
      array( 'type' => 'file', 'weight' => 100 )
   );
   drupal_add_js(
      drupal_get_path( 'module', 'irrigableyam' ).'/views-view-iygallery.js',
      array( 'type' => 'file', 'weight' => 150 )
   );
   drupal_add_js(
      $gallery_js,
      array( 'type' => 'inline', 'weight' => 155 )
   );

   global $iygallery_image_markup;
   global $iygallery_thumb_markup;
   $iygallery_image_markup = array();
   $iygallery_thumb_markup = array();

   // Sanity checks.
   if(
      'pager' == $vars['view']->query->pager->plugin_type &&
      0 != $vars['view']->query->pager->options['items_per_page']
   ) {
      drupal_set_message(
         t(
            'This view requires the pager to be disabled (set to all items '.
            'per page).'
         ),
         'error'
      );
   }

   // TODO: Extract the image style from the view and insert dynamic CSS to size
   //       it.

   $image_styles = image_styles();
   foreach(
      $image_styles[$vars['options']['slide_image_style']]['effects'] as
      $image_effect_iter
   ) {
      if( array_key_exists( 'width', $image_effect_iter['data'] ) ) {
         $vars['options']['size_image']['width'] =
            $image_effect_iter['data']['width'];
      }
      if( array_key_exists( 'height', $image_effect_iter['data'] ) ) {
         $vars['options']['size_image']['height'] =
            $image_effect_iter['data']['height'];
      }
   }
   foreach(
      $image_styles[$vars['options']['slide_thumb_style']]['effects'] as
      $image_effect_iter
   ) {
      if( array_key_exists( 'width', $image_effect_iter['data'] ) ) {
         $vars['options']['size_thumb']['width'] =
            $image_effect_iter['data']['width'];
      }
      if( array_key_exists( 'height', $image_effect_iter['data'] ) ) {
         $vars['options']['size_thumb']['height'] =
            $image_effect_iter['data']['height'];
      }
   }

   if(
      !array_key_exists( 'width', $vars['options']['size_image'] ) ||
      !array_key_exists( 'height', $vars['options']['size_image'] ) ||
      !array_key_exists( 'width', $vars['options']['size_thumb'] ) ||
      !array_key_exists( 'height', $vars['options']['size_thumb'] )
   ) {
      drupal_set_message(
         t( 'A style must define a consistent height and width between images '.
            'for this view.' ),
         'error'
      );
   }

   // Build the rendered image and thumb lists.
   for( $i = 0 ; $i < count( $vars['rows'] ) ; $i++ ) {
      // TODO: Check for errors, like the wrong node type.
      $node_image = node_load( $vars['rows'][$i]->field_images );
      // TODO: Make sure the image node is visible.
      $vars['rows'][$i]->field_images = array(
         'nid' => $vars['rows'][$i]->field_images,
         'rendered_thumb' => $iygallery_thumb_markup[$i] = theme_image( array(
            'path' => image_style_url( 
               $vars['options']['slide_thumb_style'],
               $node_image
                  ->irrigableyam_image_field[$node_image->language][0]['uri']
            ),
            'alt' => $node_image
               ->irrigableyam_image_field[$node_image->language][0]['alt'],
            'title' => $node_image
               ->irrigableyam_image_field[$node_image->language][0]['title'],
            'attributes' => array(
               // XXX: Only show if not null.
               // 'width' => $thumbnail_size[0],
               // 'height' => $thumbnail_size[1]
            ),
         ) ),
         'rendered_full' => $iygallery_thumb_markup[$i] = theme_image( array(
            'path' => image_style_url( 
               $vars['options']['slide_image_style'],
               $node_image
                  ->irrigableyam_image_field[$node_image->language][0]['uri']
            ),
            'alt' => $node_image
               ->irrigableyam_image_field[$node_image->language][0]['alt'],
            'title' => $node_image
               ->irrigableyam_image_field[$node_image->language][0]['title'],
            'attributes' => array(
               // XXX: Only show if not null.
               // 'width' => $thumbnail_size[0],
               // 'height' => $thumbnail_size[1]
            ),
         ) ),
      );

      // Clean up for the result.

      //dpm( $vars['rows'][$i] );

      //dpm( $vars );

      //$vars['view']->query->pager = null;
   }
   */
}

function views_spin_carousel_views_query_alter( &$view, &$query ) {
   /* $query->add_field(
      'node',
      'nid',
      'nid'
   );
   $query->add_field(
      'node',
      'created',
      'created'
   );
   $query->add_field(
      'node',
      'title',
      'title'
   );
   $query->add_field(
      'field_data_field_images',
      'field_images_nid',
      'field_images'
   );
   $query->add_field(
      'field_data_body',
      'body_value',
      'body'
   );
   $query->add_field(
      'field_data_body',
      'body_summary',
      'summary'
   ); */
   //dpm( $query );
}

