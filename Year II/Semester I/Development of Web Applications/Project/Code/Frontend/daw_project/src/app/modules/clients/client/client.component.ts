import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Subscription } from 'rxjs';
import { Client } from 'src/app/interfaces/client';
import { ClientsService } from 'src/app/services/clients.service';

@Component({
  selector: 'app-client',
  templateUrl: './client.component.html',
  styleUrls: ['./client.component.scss']
})
export class ClientComponent implements OnInit {

  public subscription!: Subscription;
  public id!: number;
  public client: Client = {
    clientId: 0,
    clientLastName: '',
    clientFirstName: '',
    deliveryAddressId: 0,
    country: '',
    city: '',
    street: '',
    streetNumber: 0
  };

  constructor(
    private route: ActivatedRoute,
    private clientsService: ClientsService
  ) { }

  ngOnInit(): void {
    this.subscription = this.route.params.subscribe(params => {
      this.id = +params['id'];
      if (this.id) {
        this.getClientById();
      }
    });
  }

  public getClientById(): void {
    this.clientsService.getClientById(this.id).subscribe({
      next: (result: Client) => {
        console.log(result);
        this.client = result;
      },
      error: (e) => console.error(e)
    });
  }

}
