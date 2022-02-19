import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { Subscription } from 'rxjs';
import { PcComponent } from 'src/app/interfaces/pc-component';
import { PcComponentsService } from 'src/app/services/pc-components.service';

@Component({
  selector: 'app-pc-part',
  templateUrl: './pc-part.component.html',
  styleUrls: ['./pc-part.component.scss']
})
export class PcPartComponent implements OnInit {

  public subscription!: Subscription;
  public user = {roles: [localStorage.getItem('Role')]};
  public id!: number;
  public part: PcComponent = {
    componentId: 0,
    componentName: '',
    seller: '',
    recommendedForGaming: false,
    price: 0
  };

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private pcComponentsService: PcComponentsService
  ) { }

  ngOnInit(): void {
    this.subscription = this.route.params.subscribe(params => {
      this.id = +params['id'];
      if (this.id) {
        this.getComponentById();
      }
    });
  }

  public getComponentById(): void {
    this.pcComponentsService.getComponentById(this.id).subscribe({
      next: (result: PcComponent) => {
        console.log(result);
        this.part = result;
      },
      error: (e) => console.error(e)
    });
  }

  public redirect(): void {
    this.router.navigate(['../pc-components']);
  }

}
