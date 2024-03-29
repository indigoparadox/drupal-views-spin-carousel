<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

/* 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

class views_plugin_style_spin_carousel extends views_plugin_style {
   function options( &$options ) {
      $options['front_fields'] = array( 'default' => '' );
      $options['flipper_width'] = array( 'default' => 0 );
      $options['flipper_height'] = array( 'default' => 0 );
      $options['auto_timeout'] = array( 'default' => 0 );
      $options['previous_label'] = array( 'default' => t( 'Previous' ) );
      $options['next_label'] = array( 'default' => t( 'Next' ) );
   }

   function options_form( &$form, &$form_state ) {

      $form['front_fields'] = array(
         '#type' => 'textfield',
         '#title' => t( 'Front Fields' ),
         '#description' => t( 'A space-separated list of field machine names. '.
            'The specified fields, if detected in the view, will always '.
            'appear on the front of the flipper. The rest will always appear '.
            'on the back.' ),
         '#default_value' => $this->options['front_fields'],
      );

      // TODO: Validate that width/height are numeric.

      $form['flipper_width'] = array(
         '#type' => 'textfield',
         '#title' => t( 'Flipper Width' ),
         '#description' => t( 'The width of each flippable item in the '.
            'carousel.' ),
         '#default_value' => $this->options['flipper_width'],
      );

      $form['flipper_height'] = array(
         '#type' => 'textfield',
         '#title' => t( 'Flipper Height' ),
         '#description' => t( 'The height of each flippable item in the '.
            'carousel.' ),
         '#default_value' => $this->options['flipper_height'],
      );

      $form['auto_timeout'] = array(
         '#type' => 'textfield',
         '#title' => t( 'Automatic timeout' ),
         '#description' => t( 'The number of seconds until the carousel '.
            'automatically rotates. Leave empty in order to keep the '.
            'carousel in position until the viewer clicks Next or Previous.' ),
         '#default_value' => $this->options['slide_timeout'],
      );

      $form['previous_label'] = array(
         '#type' => 'textfield',
         '#title' => t( '"Previous" thumbnails link label' ),
         '#description' => t( 'The text that will appear in the thumbnail '.
            'pager links.' ),
         '#default_value' => $this->options['previous_label'],
      );

      $form['next_label'] = array(
         '#type' => 'textfield',
         '#title' => t( '"Next" thumbnails link label' ),
         '#description' => t( 'The text that will appear in the thumbnail '.
            'pager links.' ),
         '#default_value' => $this->options['next_label'],
      );
   }
}

